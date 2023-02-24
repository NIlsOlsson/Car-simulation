#version 110\n
varying vec3 color;\n
void main()\n
{\n
    gl_FragColor = vec4(color, 1.0);\n
}\n