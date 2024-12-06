#include "fwk.h"

#if 0

// -----------------------------------------------------------------------------
// image

// Image: manipulating functions
struct nk_image image_file(const char* filename);
struct nk_image image_load(const void* membuf, int membufSize);
void image_free(struct nk_image* img);

#define APP_IS_POWER_OF_2(value) ((value & (value - 1)) == 0)

struct nk_image nk_image_create(unsigned char *data, int x, int y, int n) {
    GLuint tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    #if (defined(APP_USE_OPENGL) && (APP_USE_OPENGL == NGL_ES2)) || defined(__EMSCRIPTEN__)
        /* WebGL via Emscripten */
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, x, y, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        
        if (APP_IS_POWER_OF_2(x) && APP_IS_POWER_OF_2(y)) {
            glGenerateMipmap(GL_TEXTURE_2D);
        } else {
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        }
    #else
        /* Desktop OpenGL */
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_NEAREST);
        
        #if !defined(GL_GENERATE_MIPMAP)
            /* from GLEW.h, OpenGL 1.4 only! */
            #define GL_GENERATE_MIPMAP 0x8191
        #endif
            
        #if defined(APP_USE_OPENGL) && (APP_USE_OPENGL > 2)
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, x, y, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        #else
            glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE); 
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, x, y, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        #endif

    #endif /* EMSCRIPTEN */
    
    stbi_image_free(data);
    return nk_image_id((int)tex);
}

struct nk_image image_load(const void* membuf, int membufSize) {
    int x,y,n;    
    unsigned char *data = stbi_load_from_memory((const stbi_uc*) membuf, membufSize, &x, &y, &n, 0);
    return nk_image_create(data, x, y, n);
}

struct nk_image image_file(const char* filename) {
    int x,y,n;
    unsigned char *data = stbi_load(filename, &x, &y, &n, 0);
    return nk_image_create(data, x, y, n);
}

void image_free(struct nk_image* img) {
    if( img != NULL ) {
        glDeleteTextures(1,(const GLuint*)&(img->handle.id) );
        img->w = 0;
        img->h = 0;
        img = NULL;
    }
}
#endif


void render(void *arg) {
    if( !window_swap() ) return;

    static int integer = 42;
    static bool toggle = true;
    static bool boolean = true;
    static float floating = 3.14159;
    static float float2[2] = {1,2};
    static float float3[3] = {1,2,3};
    static float float4[4] = {1,2,3,4};
    static float rgb[3] = {0.84,0.67,0.17};
    static float rgba[4] = {0.67,0.90,0.12,1};
    static float slider = 0.5f;
    static float slider2 = 0.5f;
    static char string[64] = "hello world 123";
    static int item = 0; const char *list[] = {"one","two","three"};
    static bool show_dialog = false;
    static uint8_t bitmask = 0x55;

    if( ui_begin("UI", 0)) {
        if( ui_label("my label")) {}
        if( ui_label("my label with tooltip@built on " __DATE__ " " __TIME__)) {}
        if( ui_separator() ) {}
        if( ui_bool("my bool", &boolean) ) puts("bool changed");
        if( ui_int("my int", &integer) ) puts("int changed");
        if( ui_float("my float", &floating) ) puts("float changed");
        if( ui_string("my string", string, 64) ) puts("string changed");
        if( ui_separator() ) {}
        if( ui_slider("my slider", &slider)) puts("slider changed");
        if( ui_slider2("my slider 2", &slider2, va("%.2f", slider2))) puts("slider2 changed");
        if( ui_separator() ) {}
        if( ui_list("my list", list, 3, &item ) ) puts("list changed");
        if( ui_separator() ) {}
        if( ui_color3f("my color3", rgb) ) puts("color3 changed");
        if( ui_color4f("my color4@this is a tooltip", rgba) ) puts("color4 changed");
        if( ui_separator() ) {}
        if( ui_float2("my float2", float2) ) puts("float2 changed");
        if( ui_float3("my float3", float3) ) puts("float3 changed");
        if( ui_float4("my float4", float4) ) puts("float4 changed");
        if( ui_bits8("my bitmask", &bitmask) ) printf("bitmask changed %x\n", bitmask);
        if( ui_separator() ) {}
        if( ui_toggle("my toggle", &toggle) ) printf("toggle %s\n", toggle ? "on":"off");
        if( ui_separator() ) {}
        if( ui_image("my image", texture_checker().id, 0, 0) ) { puts("image clicked"); }
        if( ui_button("my button") ) { puts("button clicked"); show_dialog = true; }
        if( ui_dialog("my dialog", __FILE__ "\n" __DATE__ "\n" "Public Domain.", 2/*two buttons*/, &show_dialog) ) {}

        ui_end();
    }
}

int main() {
    window_create(0.75f, 0);
    window_loop(render, NULL);
}
