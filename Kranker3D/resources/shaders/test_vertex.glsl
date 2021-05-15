 #version 430 core
    in vec3 pos;
    out vec2 texcoord;
    uniform float iTime;
    uniform mat4 transform;
    uniform mat4 view;
    uniform mat4 projection;
    void main()
    {
        gl_Position = projection*view*transform*vec4(pos, 1);
        texcoord = gl_Position.xy;
    }
