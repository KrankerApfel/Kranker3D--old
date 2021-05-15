#version 430 core
    in vec2 texcoord;  
    uniform float iTime;
    uniform sampler2D main_tex_sampler;
    void main() 
    {
        vec4 color = vec4(iTime,texcoord.y,cos(iTime)*texcoord.y,1.);
         gl_FragColor = texture(main_tex_sampler, texcoord)*color;

    }