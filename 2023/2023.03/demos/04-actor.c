// actor controller demo: anims, anim blending, input, math
// - rlyeh, public domain.
//
// Compile with:
//    `make     demos\04-actor.c` (windows)
// `sh MAKE.bat demos/04-actor.c` (linux, osx)

#include "fwk.h"

int main() {
    // create window (75% sized, MSAAx4)
    window_create(75, WINDOW_MSAA4);
    window_title(__FILE__);

    // set up our players
    struct player_t {
        const char *name;
        model_t mdl;
        anim_t idle, run;     // anim clips
        float keys[4], scale; // up,down,left,right
        vec2 inertia;         // [forward,yaw]
        vec3 pivot, speed;    // [pitch,yaw,roll] [turn speed,forward speed,anim speed fps]
        vec3 pos, dir, pad;   // [position] [facing dir] [gamepad accumulator]
        bool notified;
    } player[] = {
        { "PLAYER-1", model("kgirls01.fbx", 0), loop(0,60,0.25,0), loop(66,85,0.25,0), // idle anim [0..60], run anim [66..85]
            {KEY_UP,KEY_DOWN,KEY_LEFT,KEY_RIGHT}, 2, {0.90,0.80}, {-100}, {3, 0.30, 30}, {0}, {1} },
        { "PLAYER-2", model("george.fbx", 0), loop(0,100,0.25,0), loop(372,396,0.25,0), // idle anim [0..100], run anim [372..396]
            {KEY_I,KEY_K,KEY_J,KEY_L}, 1, {0.95,0.90}, {-90,-90}, {1.75, 0.25, 24}, {-5}, {1} },
        { "PLAYER-3", model("alien.fbx", 0), loop(110,208,0.25,0), loop(360,380,0.25,0), // idle anim [110..208], run anim [360..380]
            {KEY_W,KEY_S,KEY_A,KEY_D}, 0.85, {0.85,0.75}, {-90,-90}, {3.5, 0.35, 60}, {5}, {1} }
    };

    // camera that points to origin, skybox, and a background tune
    camera_t cam = camera();
    skybox_t sky = skybox("cubemaps/stardust", 0);
    audio_play( audio_stream("waterworld-map.fur"), 0 );

    // game loop
    while( window_swap() ) {
        // world: skybox, position markers and ground grid
        skybox_render(&sky, cam.proj, cam.view);
        for( int i = 0; i < countof(player); ++i )
            ddraw_position_dir(player[i].pos, player[i].dir, 1.0f);
        ddraw_grid(0);
        ddraw_flush();

        // move and render players
        for( int i = 0; i < countof(player); ++i ) {
            struct player_t *p = &player[i];

            // accumulate inputs
            float yaw = input(p->keys[2]) - input(p->keys[3]);
            float fwd = input(p->keys[0]) - input(p->keys[1]); if(fwd<0) fwd = 0;
            p->pad.x = p->pad.x * p->inertia.y + yaw * (1-p->inertia.y);
            p->pad.y = p->pad.y * p->inertia.x + fwd * (1-p->inertia.x);

            // rotate yaw dir, then apply into position
            p->dir = rotatey3(p->dir, p->speed.x * p->pad.x);
            p->pos = add3(p->pos, scale3(p->dir, p->speed.y * p->pad.y));

            // animate clips and blend
            anim_t *primary = fwd ? &p->run : &p->idle;
            anim_t *secondary = fwd ? &p->idle : &p->run;
            model_animate_blends(p->mdl, primary, secondary, window_delta() * p->speed.z);

            // render model. transforms on top of initial pivot and scale
            mat44 M; compose44(M, p->pos, eulerq(add3(p->pivot,vec3(atan2(p->dir.z,p->dir.x)*180/C_PI,0,0))),vec3(p->scale,p->scale,p->scale));
            model_render(p->mdl, cam.proj, cam.view, M, 0);

            // ui
            if( yaw||fwd ) if( !p->notified ) p->notified = 1, ui_notify(0, va(ICON_MD_GAMEPAD " %s joined the game.", p->name));
            ddraw_text(p->pos, 0.01, va("%s: %6.3f", fwd?"run":"idle", (fwd ? p->run : p->idle).timer ));
        }

        // look at the players that are moving; center of their triangle otherwise.
        float A = len3(player[0].pad); if(A<0.01) A=0;
        float B = len3(player[1].pad); if(B<0.01) B=0;
        float C = len3(player[2].pad); if(C<0.01) C=0;
        float weight = A + B + C;
        if( weight ) A /= weight, B /= weight, C /= weight; else A = B = C = 0.33333;
        vec3 target = add3(add3(scale3(player[0].pos,A), scale3(player[1].pos,B)), scale3(player[2].pos,C));
        // smooth target before sending to camera
        static vec3 smooth; camera_lookat(&cam, smooth = mix3(target,smooth,!weight ? 0.98 : 0.95));

        // ui
        if( ui_panel("Controls", 0) ) {
            ui_label2("Girl",  ICON_MD_GAMEPAD " CURSOR keys");
            ui_label2("Alien", ICON_MD_GAMEPAD " W,A,S,D keys");
            ui_label2("Robot", ICON_MD_GAMEPAD " I,J,K,L keys");
            ui_panel_end();
        }
    }
}
