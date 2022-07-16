<h1 align="center"><a href="https://bit.ly/-fwk-">F·W·K</a></h1>
<p align="center">3D game framework in C, with Luajit bindings now.</p>

<p align="center">
<img src="https://i.imgur.com/sInbRoA.gif"/><br/>
</p>

<!--
editor1 | editor2
:-: | :-:
<video src='https://user-images.githubusercontent.com/35402248/174457347-f787a6a2-aac8-404c-a5da-f44310c3d432.mp4' width=180></video> | <video src='https://user-images.githubusercontent.com/35402248/174457144-40098726-e78f-4284-be68-783ff12f350f.mp4' width=180></video>
-->

## Goals
- [x] ~~C++~~. C.
- [x] ~~Fast~~. Naive.
- [x] ~~Modern~~. Simple.
- [x] ~~Full featured~~. Small.
- [x] ~~Rich build system~~. Single file.
- [x] ~~Royaltie fee~~. Free and unlicensed.

## Features ᕦ(ᐛ)ᕤ
- [x] Pipeline: configurable and integrated [asset pipeline](fwk.ini).
- [x] Embedded: single-file, all dependencies included.
- [x] Compiler: MSVC, MINGW64, TCC, GCC, clang and emscripten.
- [x] Linkage: Both static linkage and dynamic .dll/.so/.dylib support. 
- [x] Platform: Windows, Linux and OSX. Partial HTML5/Web support.
- [x] DS: hash, sort, array/vector, map, set.
- [x] Math: rand, noise, ease, vec2/3/4, mat33/34/44, quat.
- [x] Geometry: ray, line, plane, aabb, sphere, capsule, triangle, poly and frustum.
- [x] Window: windowed, soft/hard fullscreen, msaa, icon, cursor handling.
- [x] Input: keyboard, mouse and gamepads.
- [x] Script: Lua scripting, Luajit bindings.
- [x] Network: downloads (HTTPS) and sockets (TCP/UDP). <!-- [*] Object, GameObject, W/ECS -->
- [x] UI: color3/4, button, list, slider, toggle, checkbox, editbox, dialog, image, menus, windows
- [x] Font: TTF, OTF and TTC. Basic syntax highlighter. Glyph ranges. Atlasing.
- [x] Localization/I18N: XLSX and INI. Unicode.
- [x] Image: JPG, PNG, BMP, PSD, PIC, PNM, ICO.
- [x] Texture: KTX/2, PVR, DDS, ASTC, BASIS, HDR, TGA.
- [x] Texel: Depth, R, RG, RGB, RGBA, BC1/2/3/4/5/6/7, PVRI/II, ETC1/2, ASTC.
- [x] Audio: WAV/FLAC, OGG/MP1/MP3, MOD/XM/S3M/IT, SFXR and MID.
- [x] Video: MP4, MPG, OGV, MKV, WMV and AVI. Also, MP4 recording with MPEG-1 fallback.
- [x] Model: IQM/E, GLTF/2, GLB, FBX, OBJ, DAE, BLEND, MD3/5, MS3D, SMD, X, 3DS, BVH, DXF, LWO.
- [x] Render: PBR (metallic-roughness) workflow. <!-- @todo: merge demo_pbr.c rendering code into fwk_render.c -->
- [x] Render: Cubemaps, panoramas and spherical harmonics. Rayleigh/Mie scattering.
- [x] Render: Post-effects (SSAO,FXAA1/3,CRT,Contrast,Grain,Outline,Vignette...).
- [x] Render: 3D Anims, skeletal anims, hardware skinning and instanced rendering.
- [x] Render: 3D Debugdraw, batching and vectorial font.
- [x] Render: 2D Sprites, spritesheets, AA zooming and batching.
- [x] Compression: DEFLATE, LZMA, LZ4, ULZ, BALZ, BCM, CRUSH, LZW3, LZSS and PPP.
- [x] Virtual filesystem: ZIP, PAK, TAR and DIR.
- [x] Level data: JSON, JSON5, SJSON, XML, INI.
- [x] Disk cache.
- [x] Scene handling.
- [x] Profiler, stats and leaks finder.
- [x] [Documentation (wip)](https://bit.ly/-fwk-).

## Roadmap ᕕ(ᐛ)ᕗ (in order of arrival; ✱: partial support)
- [ ] Editor: gizmos✱, scene tree, property editor✱, load/save✱, undo/redo✱, copy/paste. <!-- editor = tree of nodes. levels and objects are nodes, and widgets are also nodes --><!-- you can perform actions on nodes, with or without descendants, top-bottom or bottom-top --><!-- operations include load/save, reset, undo/redo, play/render vis on/off/alpha logic on/off/other ddraw on/off log on/off, etc --> 
- [ ] Level objects: volumes✱, triggers, platforms, streaming. 
- [ ] World: W/ECS, gameobj, serialization/merge, diff/patch. 
- [ ] Scene: toggles on/off (billboards✱, materials, un/lit, cast shadows, wireframe, skybox✱/mie✱, collide✱, physics).
- [ ] Scene: node singleton display, node console, node labels, node outlines✱. <!-- node == gameobj ? -->
- [ ] Math: quat2, bezier, catmull.
- [ ] Render: Materials (colors✱, textures✱, matcaps✱, videos✱, shadertoys✱). Shadertoys as post-fx✱. <!--materials as postfx, as they have an update() method -->
- [ ] Render: Hard/soft shadow mapping and baked lightmaps.
- [ ] Script: DLL✱ (module->plugin/sys), Lua✱, Luajit✱, Teal✱ and TypeScript.
- [ ] Network: NAT traversal. Socketless API, message API and pub/sub wrappers (enet/websocket).
- [ ] Pipeline: Extend: shaders, bindings. Per-platform✱, per-type✱, per-asset options. GIF, PKM.
- [ ] Pipeline: Extend atlas (sprite/lightmaps). Fit packing (sprites).
- [ ] Pipeline: Extend bindings and messaging: parse C headers during cooking stage. <!-- msgs,docs,refl,meta,lua -->
- [ ] Maybe: AI/Logic pass.
- [ ] Maybe: Animation pass.
- [ ] Maybe: VM/Replication pass.
- [ ] Maybe: Mobile/WASM/HTML5✱ pass. 
- [ ] Maybe: Lighting pass.
- [ ] Maybe: Node/Graph editor. <!-- reused into materials, animgraphs and blueprints -->
- [ ] Maybe: Tiled maps and 2D spines. Sprite parallaxs.
- [ ] Maybe: Font text layout and shaping, underlining, soft/hard shadows, outlines.
- [ ] API: Fewer and better examples.
- [ ] API: Discuss API and freeze it.
- [ ] API: Document everything. 

<!--

## 2021 Discord poll
A. Core pass: struct serialization, file checksums (crc32, md5, sha1), math (quat2, bezier, catmull).
B. Network pass: NAT Traversal, Socketless API, Message API, pub/sub wrappers (enet/websocket).

C. World pass: world/entity/component/systems, serialization (load/save/merge), diff/patch. #3
D. Scene pass: scenegraph, BVH, frustum culling, toggleviews (billboards, materials, un/lit, cast shadows, wireframe, skybox/mie, collide, physics). #3
X. VM pass: auto/VM replication, manual/replication channels, node sharding/clustering.

E. Editor pass: gizmos, scene tree, property editor, load/save, undo/redo, copy/paste, VCS integration. #1
F. Level pass: volumes, triggers, platforms, level streaming. #2
G. Debug pass: object singleton display, object console, object labels, object outlines.

H. Material pass: colors, textures, matcaps, videos, shadertoys. Shadertoys as post-fx.
I. Lighting pass: hard/soft shadow mapping, omnilights, spotlights, VSM, CSM and baked lightmaps.
J. Render pass: reflection probes, object instancing, billboards, impostors, mesh lods, decals.
K. FX pass: particles and emitters (TLFX), kawaii physics, clothes, breakables.

L. Animation pass: playlists, blend/shapes, ik/bones, animgraph/controllers. Also 2D skeletal sprites (Spine).
M. Logic pass: game state, h/fsm, planning goal, behavior trees, navpaths/waypoints, pathfinding, swarm/flocks. 
N. Script pass: DLL (module->plugin/sys), Lua, Luajit, Teal and TypeScript. Docs/Refl/Meta binding tool (during cook stage).
O. Social pass: Achievements, Scores, Rankings, Friends, Invites, Steam/Itchio 3rd-party store integrations, etc.
P. UI/UX pass: HUD, UI Widgets, user/system notifications/toasts, touch input, touch gestures.

Q. Portability pass: Mobile iOS/Android, Web/WASM, RaspberryPi. #4
R. Documentation pass: API, functions, samples, examples, pipeline. #5

// almost done:
// [x] shadertoy textures
// [*] billboards (follow sprite API? state instead? ie, billboard(true); before rendering?)
// [ ] soft shadows (vsm, vsmcube)

// nice to have:
// [ ] fix leaks and todos
// [ ] fwk_app: cpu usage, orientation
// [ ] fwk_input: cursor, mouse clip, mouse wrap,
// [ ] zip0 seek-vfs optimization. zip_append_file is suboptimal, and requires tons of contiguous memory for giant files.
// [ ] expose uniforms as ui options, also model_uniform();
// [ ] font: M/SDF https://github.com/WilliamBundy/wiggle https://github.com/Chlumsky/msdf-atlas-gen
// [ ] lod: https://github.com/songrun/SeamAwareDecimater
// [ ] lightmaps: https://blackpawn.com/texts/lightmaps/default.html 
// [ ] https://github.com/jpcy/xatlas

// plan:
//[ ] Script: Refl/meta binding tool (during cook stage).
//    fwk_cook (*.c, *.h) as .proto/.pbc maybe, free reflection+automatic bindings
//[ ] cam: friction, projections (dimetric, isometric, ...)
//[ ] Render: Materials (textures, matcaps, videos, shadertoys).
//    material: fixed color, texture or script that returns color
//    animated textures (shadertoys, videos)
//[ ] Pipeline: Extend asset pipeline (shaders, bindings, xml). Asset options.
//      cook: hlsl2glsl (XShaderCompiler), hlsl2spirv (dxc), spirv2many (spirv-cross), glsl2many (sokol-shdc)
//      cook: tiled2json, spine2json, tlfx22json
// 6) anims, I (playlist: forward/backwards/loop/rewind), II (blend/shapes), III (ik/bone), IV (graph/controller)
//    blend anims, animtracks+animevents, ~~draw skeleton~~, additive anims,
//    fwk_data: quantization: ~~half, quant, microfloat~~.
//    anim; keyframes[] { frame+delay,frame+delay,... }, anim duration, anim flip,
//    anim tracks / anim events
//[ ] Maybe: AI/Logic pass.
//    app: app state manager (h/fsm modules)
//    scripts: states, signals, h/fsm, coroutines, load/save context
//    ai: h/fsm for level objects and small enemies, planning GOAL, BTrees,
//    nav: navpaths, waypoints, navigation, pathfinding (jps.hh), A*, A* GOAL planning, swarm/flocks,
//[ ] Maybe: VM/ECS/Replication pass.
// 8) vm/ecs core + engines: custom frontends & backends
//    vm: ram, workqueues, threading, priorities, load/save
//    service protocols: websocket bqqbarbhg/bq_websocket, https, handshake
//    databases, services, quotas, black/whitelists, etc
// 7) network replication & messaging
//    network: replication, dead reckoning, interpolation, extrapolation, bandwidth
//    network: messaging: un/reliable, fragmentation, priority, etc
//    network: topologies: bus, star, p2p, pubsub, etc
//    network: filesystem
//    int send_game_state(void *ptr, int len, int flags); PROTOCOL_V1|QUANTIZE|COMPRESS|RLE
//    int recv_game_state(); compensate, extrapolate, intrapolate(); lerp();
//[ ] Maybe: Lighting/PBR pass.
// 9) render+
//    lighting: vsm,vsmcube (per @procedural's request)
//    2d: billboards
//    PBR/IBL/materials (from Foxotron+sgorsten) + shading models
//    lightmapping/xatlas (demos), reflection probes
//    ~~instancing~~, frustum culling, impostors, mesh lods,
//    renderbuckets
//    decals
//    tessellation
//    2d: spines, particles (tlfx2)
//    reverse-z {
//    fbo attach format D16_UNORM -> D32_SFLOAT
//    pipeline depth compare LEQUAL -> GEQUAL
//    pipeline depth clear 1.0 -> 0.0
//    proj matrix: float a = zfar / (zfar - znear); -> float a = -znear / (zfar - znear);
//    proj matrix: float b = (-znear * zfar) / (zfar - znear); -> float b = (znear * zfar) / (zfar - znear);
//    }

    char* os_exec(...) -> int rc = popen(...); [...] return va("%8d,%s", rc, output);
    char *result = os_exec("dir *.f")
    int rc = atoi(result);
    char *log = result+9;

-->

## Gallery
<p align="center">
<img src="https://raw.githubusercontent.com/r-lyeh/FWK/master/art/demos/demo_script.png"    width="204px" title="Script."/>
<img src="https://raw.githubusercontent.com/r-lyeh/FWK/master/art/demos/demo_font.png"      width="204px" title="Fonts."/>
<img src="https://raw.githubusercontent.com/r-lyeh/FWK/master/art/demos/demo_collide.png"   width="204px" title="Collision."/>
<img src="https://raw.githubusercontent.com/r-lyeh/FWK/master/art/demos/demo_model.png"     width="204px" title="Model."/>
<img src="https://raw.githubusercontent.com/r-lyeh/FWK/master/art/demos/demo_scene.png"     width="204px" title="Scene."/>
<img src="https://raw.githubusercontent.com/r-lyeh/FWK/master/art/demos/demo_sprite.png"    width="204px" title="Sprite."/>
<img src="https://raw.githubusercontent.com/r-lyeh/FWK/master/art/demos/demo_shadertoy.png" width="204px" title="Shadertoy."/>
<img src="https://raw.githubusercontent.com/r-lyeh/FWK/master/art/demos/demo_cubemap.png"   width="204px" title="Cubemaps and SH."/>
<img src="https://raw.githubusercontent.com/r-lyeh/FWK/master/art/demos/demo_video.png"     width="204px" title="Video."/>
<img src="https://raw.githubusercontent.com/r-lyeh/FWK/master/art/demos/demo_pbr.png"       width="204px" title="PBR."/>
<img src="https://raw.githubusercontent.com/r-lyeh/FWK/master/art/demos/demo_instanced.png" width="204px" title="Instancing."/>
<img src="https://raw.githubusercontent.com/r-lyeh/FWK/master/art/demos/editor.png" width="204px" title="Editor."/>
<br/>
</p>

## Hello FWK
```C
#include "fwk.h" // Minimal C sample
int main() {
    window_create(75.0, 0); // 75% size, no extra flags
    while( window_swap() && !input(KEY_ESC) ) { // game loop
        puts("hello FWK from C!");
    }
}
```

```lua
local fwk = require("fwk") -- Minimal Lua sample
fwk.window_create(75.0,0) -- 75% size, no extra flags
while fwk.window_swap() and fwk.input(fwk.KEY_ESC) == 0 do -- game loop
    print("hello FWK from Lua!")
end
```

```C
#include "fwk.h" // Minimal HTML5 sample
void render(void *arg) {
    if( !input(KEY_ESC) ) { 
        puts("hello FWK from HTML5!");
    }
}
int main() {
    window_create(75.0, 0); // 75% size, no extra flags
    window_loop(render, NULL); // game loop
}
```

## Build (as static library)
Type `MAKE.bat static` (Win) or `sh MAKE.bat static` (Linux/OSX) to build everything dynamically. Alternatively,

```lua
echo Win(vc)              && cl  demo.c       fwk.c
echo Win(tcc)             && tcc demo.c       fwk.c
echo Win(gcc)             && gcc demo.c       fwk.c -lws2_32 -lgdi32 -lwinmm -ldbghelp -lole32 -lcomdlg32
echo Linux(gcc+clang+tcc) && cc  demo.c       fwk.c -lm -ldl -lpthread -lX11
echo OSX(gcc+clang)       && cc  demo.c -ObjC fwk.c -framework cocoa -framework iokit
```
<!-- - Note: Windows: Assimp.dll may need [this package installed](https://www.microsoft.com/en-us/download/confirmation.aspx?id=30679).-->
- Note: TCC is partially supported on Windows+Linux. Beware, no threading.

## Build (as dynamic library)
Type `MAKE.bat dll` (Win) or `sh MAKE.bat dll` (Linux/OSX) to build everything staticly. Alternatively,

```lua
echo Win(vc)  && cl  fwk.c /LD     /DAPI=EXPORT && cl  demo.c fwk.lib /DAPI=IMPORT
echo Win(tcc) && tcc fwk.c -shared -DAPI=EXPORT && tcc demo.c fwk.def -DAPI=IMPORT
echo Win(gcc) && gcc fwk.c -shared -DAPI=EXPORT -o fwk.dll -lws2_32 -lwinmm -ldbghelp -lole32 -lgdi32 -lcomdlg32 -Wl,--out-implib,fwk.a && gcc demo.c fwk.a -DAPI=IMPORT
echo Linux    && cc -fPIC -shared     -o libfwk.so    fwk.c -lX11 && cc demo.c libfwk.so -DAPI=IMPORT -Wl,-rpath,./
echo OSX      && cc -ObjC -dynamiclib -o libfwk.dylib fwk.c -framework cocoa -framework iokit && cc demo.c libfwk.dylib -DAPI=IMPORT
```

## Cook
- Most asset types need to be cooked before being used in your application. Other assets like `.png` do not.
- Cooker is already embedded into you application and will scan for new contents & cook assets automatically.
- In order to achieve this, your binary needs to keep both [`fwk.ini` file](fwk.ini) and [`tools/` folder](art/editor/tools/) close together.
- Cooked assets will be written into .zipfiles close to your executable, and mounted before entering game loop.
- When distributing your game, only your binary and these .zipfiles are required.

## Amalgamation
- Depending on your IDE, you might need to [split all amalgamated](#Amalgamation) files when debugging FWK.
- Split FWK into separate files by running `MAKE.bat split` (or `sh MAKE.bat split` in Linux/OSX).
- Merge those files back into FWK by running `MAKE.bat join` (or `sh MAKE.bat join` in Linux/OSX).
- Optionally, generate a single-header distribution by executing following script:

```lua
echo // This C file is a header that you can #include.  Do #define FWK_C  > fwk-single-header.h
echo // early in **one** C compilation unit to unroll the implementation >> fwk-single-header.h
echo // The FWK_C symbol **must be defined in a C file**; C++ wont work. >> fwk-single-header.h
type art\docs\ref\3rd\3rd_glad.h >> fwk-single-header.h
type fwk.h                       >> fwk-single-header.h
echo #ifdef FWK_C                >> fwk-single-header.h
echo #pragma once                >> fwk-single-header.h
echo #define FWK_3RD             >> fwk-single-header.h
type fwk                         >> fwk-single-header.h
type fwk.c                       >> fwk-single-header.h
echo #endif // FWK_C             >> fwk-single-header.h
```

## Extra tips
- Any ico/png file matching the executable name will be automatically used as app icon.
- Dropped files into game window will be imported & saved into [`art/import`](art/import) folder.
- Update the gamepad controller database by upgrading the [`gamecontrollerdb.txt`](art/editor/input) file.
- Cancel entire cooking stage by pressing `ESC key` (not recommended).
- Disable automatic cooking by using `--with-cook-jobs=0` flag (not recommended).
- Cook from command-line by running [`cook.*` binaries](art/editor/tools/). 
- Linux/OSX users can optionally install wine and use the Windows pipeline instead (by using `--with-wine` flag).
- Generate a Visual Studio solution by dropping `fwk.h, fwk.c and fwk` files into it.
- Faster builds by typing `MAKE.bat tcc` (Win/Linux).
- Get smaller .exes by compiling with `/Os /Ox /O2 /Oy /GL /GF /MT /DNDEBUG /Gw /link /OPT:ICF /LTCG` (vc).
<!-- - On windows + vc, you can use `make bindings` or `make docs` to generate everything prior to a release -->

## Bindings
- Luajit: Luajit bindings are provided in the [auto-generated fwk.lua file](art/demos/lua/fwk.lua).
- Nelua: [Nelua bindings](https://github.com/Rabios/nelua-fun/tree/main/fwk) provided by Rabia Alhaffar.

## Credits (Artwork + demos)
- [DavidLam](https://en.wikipedia.org/wiki/Tokamak_(software)), for tokamak physics engine (ZLIB). 
- [FMS_Cat](https://gist.github.com/FMS-Cat/a1ccea3ce866c34706084e3526204f4f), for nicest VHS/VCR shader around (MIT).
- [Goblin165cm](https://sketchfab.com/3d-models/halloween-little-witch-ccc023590bfb4789af9322864e42d1ab), for witch 3D model (CC BY 4.0).
- [Nanofactory](https://sketchfab.com/3d-models/kgirls01-d2f946f58a8040ae993cda70c97b302c), for kgirls01 3D model (CC BY-NC-ND 4.0).
- [Quaternius](https://www.patreon.com/quaternius), for the lovely 3D robots (CC0).
- [Rxi](https://github.com/rxi/autobatch), for lovely sprites & cats demo (MIT).
- [wwwtyro](https://github.com/wwwtyro/glsl-atmosphere), for nicest rayleigh/mie scattering shader around (CC0).

## Credits (Tools)
- [Aaron Barany](https://github.com/akb825/Cuttlefish), for cuttlefish (APACHE2).
- [Arseny Kapoulkine](https://github.com/zeux/pugixml/), for pugixml (MIT).
- [Assimp authors](https://github.com/assimp/assimp), for assimp (BSD3).
- [Bernhard Schelling](https://github.com/schellingb/TinySoundFont), for tml.h (Zlib) and tsf.h (MIT).
- [ffmpeg authors](https://www.ffmpeg.org/), for ffmpeg (LGPL21).
- [Imagination](https://developer.imaginationtech.com/pvrtextool/), for pvrtextoolcli (ITL).
- [Krzysztof Gabis](https://github.com/kgabis/ape), for split.py/join.py (MIT).
- [Lee Salzman](https://github.com/lsalzman/iqm/tree/5882b8c32fa622eba3861a621bb715d693573420/demo), for iqm.cpp (PD).
- [Martín Lucas Golini](https://github.com/SpartanJ/eepp/commit/8552941da19380d7a629c4da80a976aec5d39e5c), for emscripten-fs.html (CC0).
- [Mattias Gustavsson](https://github.com/mattiasgustavsson/libs), for mid.h (PD).
- [Michael Schmoock](http://github.com/willsteel/lcpp), for lcpp (MIT).
- [Morgan McGuire](https://casual-effects.com/markdeep/), for markdeep (BSD2).
- [Olivier Lapicque, Konstanty Bialkowski](https://github.com/Konstanty/libmodplug), for libmodplug (PD).
- [Polyglot Team](https://docs.google.com/spreadsheets/d/17f0dQawb-s_Fd7DHgmVvJoEGDMH_yoSd8EYigrb0zmM/edit), for polyglot gamedev (CC0).
- [Tomas Pettersson](http://www.drpetter.se/), for sfxr (PD).
- [Tor Andersson](https://github.com/ccxvii/asstools), for assiqe.c (BSD).

## Credits (Runtime)
- [Barerose](https://github.com/barerose), for swrap (CC0).
- [Camilla Löwy](https://github.com/elmindreda), for glfw3 (Zlib).
- [Dave Rand](https://tools.ietf.org/html/rfc1978) for ppp (PD).
- [David Herberth](https://github.com/dav1dde/), for glad generated code (PD).
- [David Reid](https://github.com/mackron), for miniaudio (PD).
- [Dominic Szablewski](https://github.com/phoboslab/pl_mpeg), for pl_mpeg (MIT).
- [Dominik Madarász](https://github.com/zaklaus), for json5 parser (PD).
- [Eduard Suica](https://github.com/eduardsui/tlse), for tlse (PD).
- [Gargaj+cce/Peisik](https://github.com/gargaj/foxotron), for Foxotron/PBR shaders (UNLICENSE).
- [Guillaume Vareille](http://tinyfiledialogs.sourceforge.net), for tinyfiledialogs (ZLIB).
- [Haruhiko Okumura](https://oku.edu.mie-u.ac.jp/~okumura/compression/) for lzss (PD).
- [Igor Pavlov](https://www.7-zip.org/) for LZMA (PD).
- [Ilya Muravyov](https://github.com/encode84) for bcm, balz, crush, ulz, lz4x (PD).
- [Jon Olick](https://www.jonolick.com/), for jo_mp1 and jo_mpeg (PD).
- [Joonas Pihlajamaa](https://github.com/jokkebk/JUnzip), for JUnzip library (PD).
- [Juliette Focault](https://github.com/juliettef/IconFontCppHeaders/blob/main/IconsMaterialDesign.h), for the generated MD header (ZLIB).
- [Lee Salzman](https://github.com/lsalzman/iqm/tree/5882b8c32fa622eba3861a621bb715d693573420/demo), for IQM spec & player (PD).
- [Lee Salzman, V.Hrytsenko, D.Madarász](https://github.com/zpl-c/enet/), for enet (MIT).
- [Libtomcrypt](https://github.com/libtom/libtomcrypt), for libtomcrypt (Unlicense).
- [Lua authors](https://www.lua.org/), for Lua language (MIT).
- [Mattias Gustavsson](https://github.com/mattiasgustavsson/libs), for thread.h and https.h (PD).
- [Micha Mettke, Chris Willcocks, Dmitry Hrabrov](https://github.com/vurtun/nuklear), for nuklear (PD).
- [Omar Cornut, vaiorabbit](https://github.com/ocornut/imgui/pull/3627), for tables of unicode ranges (MIT-0).
- [Rabia Alhaffar](https://github.com/Rabios/ice_libs), for ice_batt.h (PD).
- [Rich Geldreich](https://github.com/richgel999/miniz), for miniz (PD).
- [Ross Williams](http://ross.net/compression/lzrw3a.html) for lzrw3a (PD).
- [Samuli Raivio](https://github.com/bqqbarbhg/bq_websocket), for bq_websocket (PD).
- [Sean Barrett](https://github.com/nothings), for stb_image, stb_image_write, stb_sprintf, stb_truetype and stb_vorbis (PD).
- [Sebastian Steinhauer](https://github.com/kieselsteini), for sts_mixer (PD).
- [Stefan Gustavson](https://github.com/stegu/perlin-noise), for simplex noise (PD).
- [Vassvik](https://github.com/vassvik/mv_easy_font), for mv_easy_font (Unlicense).
- Special thanks to [@ands](https://github.com/ands), [@barerose](https://github.com/barerose), [@datenwolf](https://github.com/datenwolf), [@evanw](https://github.com/evanw), [@glampert](https://github.com/glampert), [@krig](https://github.com/krig), [@sgorsten](https://github.com/sgorsten) and [@vurtun](https://github.com/vurtun) for their math libraries (PD,CC0,WTFPL2,CC0,PD,CC0,Unlicense,PD).

## Unlicense
This software is released into the [public domain](https://unlicense.org/). Also dual-licensed as [0-BSD](https://opensource.org/licenses/FPL-1.0.0) or [MIT (No Attribution)](https://github.com/aws/mit-0) for those countries where public domain is a concern (sigh). Any contribution to this repository is implicitly subjected to the same release conditions aforementioned.

## Links
<p>
<a href="https://github.com/r-lyeh/FWK/issues"><img alt="Issues" src="https://img.shields.io/github/issues-raw/r-lyeh/FWK.svg"/></a>
<a href="https://discord.gg/vu6Vt9d"><img alt="Discord" src="https://img.shields.io/discord/270565488365535232?color=5865F2&label=chat&logo=discord&logoColor=white"/></a><br/>

Still looking for alternatives?
[amulet](https://github.com/ianmaclarty/amulet), [aroma](https://github.com/leafo/aroma/), [astera](https://github.com/tek256/astera), [blendelf](https://github.com/jesterKing/BlendELF), [bullordengine](https://github.com/MarilynDafa/Bulllord-Engine), [candle](https://github.com/EvilPudding/candle), [cave](https://github.com/kieselsteini/cave), [chickpea](https://github.com/ivansafrin/chickpea), [corange](https://github.com/orangeduck/Corange), [cute](https://github.com/RandyGaul/cute_framework), [dos-like](https://github.com/mattiasgustavsson/dos-like), [ejoy2d](https://github.com/ejoy/ejoy2d), [exengine](https://github.com/exezin/exengine), [gunslinger](https://github.com/MrFrenik/gunslinger), [hate](https://github.com/excessive/hate), [island](https://github.com/island-org/island), [juno](https://github.com/rxi/juno), [l](https://github.com/Lyatus/L), [lgf](https://github.com/Planimeter/lgf), [limbus](https://github.com/redien/limbus), [love](https://github.com/love2d/love/), [lovr](https://github.com/bjornbytes/lovr), [mini3d](https://github.com/mini3d/mini3d), [mintaro](https://github.com/mackron/mintaro), [mio](https://github.com/ccxvii/mio), [opensource](https://github.com/w23/OpenSource), [ouzel](https://github.com/elnormous/ouzel/), [pez](https://github.com/prideout/pez), [pixie](https://github.com/mattiasgustavsson/pixie), [punity](https://github.com/martincohen/Punity), [ricotech](https://github.com/dbechrd/RicoTech), [rizz](https://github.com/septag/rizz), [tigr](https://github.com/erkkah/tigr), [yourgamelib](https://github.com/duddel/yourgamelib)
</p>
