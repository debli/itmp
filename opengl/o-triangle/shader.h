#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h> // include glad to get all the required OpenGL headers
  
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class shader
{
	private:
		int program_id;

	public:
		shader(const char * vertex_path, const char * frag_path);
		void use();
		void set_float(const char *var_name, float val);
		void set_int(const char *var_name, int val);
};

#endif
