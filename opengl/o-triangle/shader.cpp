#include "shader.h"

gl_shader::gl_shader(const char * vertex_path, const char * frag_path)
{
	std::string vertex_code;
	std::string frag_code;

	std::ifstream vertex_file;
	std::ifstream frag_file;

	vertex_file.exceptions( std::ifstream::failbit | std::ifstream::badbit );
	frag_file.exceptions( std::ifstream::failbit | std::ifstream::badbit );

    std::stringstream vertex_stream, frag_stream;

    try
    {
        vertex_file.open(vertex_path);
        frag_file.open(frag_path);

        vertex_stream << vertex_file.rdbuf();
        frag_stream   << frag_file.rdbuf();

        vertex_code   = vertex_stream.str();
        frag_code     = frag_stream.str();

        vertex_file.close();
        frag_file.close();
    }
    catch(std::ifstream::failure e)
    {
        std::cerr << "Error: cannot read shader file." ;
    }


    const char* vertex_src, *frag_src;
    vertex_src = vertex_code.c_str();
    frag_src   = frag_code.c_str();

    if (strlen(vertex_src) > 0)
    {
        unsigned int vertex_shader;
        vertex_shader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex_shader, 1, &vertex_src, NULL);
        glCompileShader(vertex_shader);

        int success;
        glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);

        if (success != 0)
        {
            char info[512];
            glGetShaderInfoLog(vertex_shader, 512, NULL, info);
            std::cout << "Error: compile vertex shader failed: " << info << std::endl;
        }
    }
}

void gl_shader::compile_vertex(const char *src)
{

}
