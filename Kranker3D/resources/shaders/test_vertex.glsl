 #version 430 core
    in vec3 pos;
    out vec3 texcoord;
    uniform float iTime;
    void main()
    {
        gl_Position = vec4(pos.x, sin(pos.y+cos(iTime)), 0, 1);
        texcoord = gl_Position.xyz;
    }
