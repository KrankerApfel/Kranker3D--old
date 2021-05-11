#version 430 core
    in vec3 texcoord;  
    uniform float iTime;
    void main() 
    {
        gl_FragColor =vec4(iTime,texcoord.y, cos(iTime)*texcoord.z , 1); 
    }