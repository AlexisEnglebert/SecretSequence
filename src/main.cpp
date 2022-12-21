#include <stdio.h>
#include <iostream>

// Don't switch these two, because glfw3 detect that glad is included 
#define GLFW_INCLUDE_NONE

#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <ft2build.h>
#include FT_FREETYPE_H  

typedef struct{
	GLFWwindow* window; //store our window
	FT_Library ft;
	FT_Face face;
}core_t;

static core_t core;

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
	// Update viewport    
    glViewport(0, 0, width, height);
}

unsigned int create_window(){

	core.window = glfwCreateWindow(640, 480, "Secret Sequence", NULL, NULL);
	if(core.window == NULL){
		std::cerr << "Failed to create window" << std::endl;
		return -1;
	}

	glfwMakeContextCurrent(core.window);
    glfwSetFramebufferSizeCallback(core.window, framebuffer_size_callback);
    
    return 1;
}

unsigned int init_opengl(){

	if(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress) == 0){
        std::cerr << "Failed to initialize Opengl context" << std::endl;
        return -1;
    }

    return 1;
}

unsigned int init_freetype(){

	if (FT_Init_FreeType(&core.ft)){
    	std::cerr << "Failed to initialize Freetype" << std::endl;
    	return -1;
	}
	if (FT_New_Face(core.ft, "fonts/arial.ttf", 0, &core.face)){
	    std::cerr << "Failed to load arial font" << std::endl;  
	    return -1;
	}

	return 1;
}
void Render(){
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(core.window);
}

int main(int argc, char ** argv){
	printf("%s \n", "Hello World !");

	if(!glfwInit()){
		std::cerr << "Failed to initialize GLFW" << std::endl;
		return -1;
	}
	
	create_window();
	init_opengl();
	init_freetype();

	while (!glfwWindowShouldClose(core.window)) {
		Render();
		
		glfwPollEvents();
	}


	glfwDestroyWindow(core.window);
	glfwTerminate();

}