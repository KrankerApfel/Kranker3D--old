#version 430 core
    in vec3 texcoord;  
    uniform float iTime;
    void main() 
    {
        gl_FragColor = vec4(texcoord.x,texcoord.y, sin(iTime) , 1); 
    }