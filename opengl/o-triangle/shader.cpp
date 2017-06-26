#include "shader.h"

gl_shader::Shader(const char * vertex_path, const char * frag_path)
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
        vertex_stream << vertex_file.rdbuf();
        frag_stream << frag.rdbuf();

        vertex_code = vertex_stream.str();
        frag_code = frag_stream.str();

        vertex_stream.close();
        frag_stream.close();
    }
    catch(std::ifstream::failure e)
    {
        std::cerr << "Error: cannot read shader file." ;
    }

    const char* vertex_str = vertex_code.c_str();
}
