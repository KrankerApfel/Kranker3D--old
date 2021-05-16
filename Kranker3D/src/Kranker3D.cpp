/*####################################################################################################################
#     Copyright(C) 2020 by T "Kranker Apfel" RKT																	 #
#     https://krankerapfel.github.io																				 #
#																													 #
#     This program is distributed under the terms of the GNU General Public License	    							 #
#																													 #
#      ██ ▄█▀ ██▀███   ▄▄▄       ███▄    █  ██ ▄█▀▓█████  ██▀███      ▄▄▄       ██▓███    █████▒▓█████  ██▓          #
#      ██▄█▒ ▓██ ▒ ██▒▒████▄     ██ ▀█   █  ██▄█▒ ▓█   ▀ ▓██ ▒ ██▒   ▒████▄    ▓██░  ██▒▓██   ▒ ▓█   ▀ ▓██▒          #
#     ▓███▄░ ▓██ ░▄█ ▒▒██  ▀█▄  ▓██  ▀█ ██▒▓███▄░ ▒███   ▓██ ░▄█ ▒   ▒██  ▀█▄  ▓██░ ██▓▒▒████ ░ ▒███   ▒██░          #
#     ▓██ █▄ ▒██▀▀█▄  ░██▄▄▄▄██ ▓██▒  ▐▌██▒▓██ █▄ ▒▓█  ▄ ▒██▀▀█▄     ░██▄▄▄▄██ ▒██▄█▓▒ ▒░▓█▒  ░ ▒▓█  ▄ ▒██░          #
#     ▒██▒ █▄░██▓ ▒██▒ ▓█   ▓██▒▒██░   ▓██░▒██▒ █▄░▒████▒░██▓ ▒██▒    ▓█   ▓██▒▒██▒ ░  ░░▒█░    ░▒████▒░██████▒      #
#     ▒ ▒▒ ▓▒░ ▒▓ ░▒▓░ ▒▒   ▓▒█░░ ▒░   ▒ ▒ ▒ ▒▒ ▓▒░░ ▒░ ░░ ▒▓ ░▒▓░    ▒▒   ▓▒█░▒▓▒░ ░  ░ ▒ ░    ░░ ▒░ ░░ ▒░▓  ░      #
#     ░ ░▒ ▒░  ░▒ ░ ▒░  ▒   ▒▒ ░░ ░░   ░ ▒░░ ░▒ ▒░ ░ ░  ░  ░▒ ░ ▒░     ▒   ▒▒ ░░▒ ░      ░       ░ ░  ░░ ░ ▒  ░      #
#     ░ ░░ ░   ░░   ░   ░   ▒      ░   ░ ░ ░ ░░ ░    ░     ░░   ░      ░   ▒   ░░        ░ ░       ░     ░ ░         #
#     ░  ░      ░           ░  ░         ░ ░  ░      ░  ░   ░              ░  ░                    ░  ░    ░  ░      #
#                                                                                                                    #
#                                                                                                                    #
#                                                                                                                    #
#                                                                                                                    #
#														present 					   							 	 #
#																					   							 	 #
#																					   							 	 #
#												                                                                     #
#                                     __ __              __             ____ ___                                     #
#                                     / //_/______ ____  / /_____ ____  |_  // _ \                                   #
#                                    / ,< / __/ _ `/ _ \/  '_/ -_) __/ _/_ </ // /                                   #
#                                   /_/|_/_/  \_,_/_//_/_/\_\\__/_/   /____/____/                                    #
#                                                                                                                    #
#												basic graphic engine                                    		 	 #
#																					   							 	 #
#																					   							 	 #
#																					   							 	 #
#                 ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,.,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,....,,,,,,,,,,,,,,,,,,,.,                    #
#                 ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,.  ,.,,,,,,,,,,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,......   .....,,,,,,,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,......,  . .....,,,,,,,,,,,,,,,,,,,,                    #
#                 ,,,.,,,,,,,,,,,,,,,,,,,.,,,,,,,,,,,,,,.........   .. .........,.,,,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,......  ..... .........,,.,,,,,,,,,,,,,,,                    #
#                 .,,,,,,,,,,,,,,,,,,,,,...,,,,,,,,,,,.....  ......  ..........,.,,,,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,,,,,,,,,,,...,,,.,,,,,......  .     ...........,,,,,,,,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,,,,,........................   .....      ........,,,,,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,,,,......  ,////////, .....  . .  .////////,  ......,,,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,,,,....  ///((((((/////* ..... ,//////////////  .....,,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,,,.... '//((((((//////////       '/////////////  .....,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,..... ./////////////////////////////////////////  .....,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,....  /////////////////////////////////.&,//////  .....,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,.....  //////////////////////////////.&@',''///// ......,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,..... .///////////////////////////'.@@,,,'//////   .....,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,....  /////////////////////////,,,,',,',//////  .....,,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,.....  ////////////////////////''/','////////  .....,,,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,,.....  .//////////////////////////,'///////  .......,,,,,,,,,,,,,.                    #
#                 ,,,,,,,,,,,,,,......  /////////////////////////////////  ......,,,,,,,,,,,,,,,.                    #
#                 .,,.,,,,,,,,,,........  ///'///((/@/%(/#/&#///(%'//'//  ........,,,,,,,,,,,,,,.                    #
#                 .,,,,,,,,,,,,,,,,....... '//'////&&(%&&&%&&(&%&&////' .......,..,,,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,,,,,,......... //'///%&&/%&%&&&(&#&////. .........,,,,,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,,,,,,,,,.......  ////%&&/(//#/(#&/(///  .......,,,,,,,,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,,,,,,,,,,........  /////////////////  ........,,,,,,,,,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,,,,,,,,,,,,.,.......       .................,,,,,,,,,,,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,,,,,,,,,,,,,,,.............................,,,,,,,,,,,,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,..................,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,,,,,,,,,,,,.,,,,,,,,,,,,........,,,,,,,,,,,,,,,,,,,.,,,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,                    #
#																					   							 	 #
#																					   							 	 #
####################################################################################################################*/

#include "stdafx.h"
#include "ui/window.h"
#include "core/rendering/shader.h"
#include "core/rendering/mesh.h"
#include "core/rendering/texture.h"
#include "../resources/meshes/DragonData.h"

#include "core/objects/camera.h"
#include "core/objects/object.h"

#include "stb_image.h"
#include "stb_image_write.h"
using namespace std;
using namespace Kranker3D;


Mesh setDragoon(vector<Kranker3D::Vertex>& vertices, vector<unsigned int>& indices)
{

	for (int i = 0; i < sizeof(DragonVertices) / sizeof(float) - 7; i += 8)
	{
		glm::vec3 pos(DragonVertices[i], DragonVertices[i + 1], DragonVertices[i + 2]);
		glm::vec3 norm(DragonVertices[i + 3], DragonVertices[i + 4], DragonVertices[i + 5]);
		glm::vec2 text(DragonVertices[i + 6], DragonVertices[i + 7]);
		vertices.push_back(Kranker3D::Vertex{ pos, norm, text });
	}

	for (int i = 0; i < sizeof(DragonIndices) / sizeof(uint16_t); i++) {
		indices.push_back(DragonIndices[i]);
	}

	return Mesh(vertices, indices);
}

//TODO : Input class

double old_mouse_x = 0.0f;
double old_mouse_y = 0.0f;
bool first_press = true;
Camera cam(800, 800);
float yaw = 0;
float pitch = 0;
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	int action = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_MIDDLE);
	if (action == GLFW_PRESS)
	{
		if (first_press)
		{
			old_mouse_x = xpos;
			old_mouse_y = ypos;
			first_press = false;
		}	

		cam.getTransform()->translate(0.00005f * glm::vec3 (xpos - old_mouse_x, old_mouse_y - ypos, 0));
	}
	else if (action == GLFW_RELEASE)
	{
		first_press = true;
	}

}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	cam.FoV -= (float)yoffset;
	if (cam.FoV < 1.0f)
		cam.FoV = 1.0f;
	if (cam.FoV > 135.0f)
		cam.FoV = 135.0f;
}



int main()
{
	
	// 1. initialization
	Window w(800, 800, "Gegege no Kitaro");	

	Shader s("D:\\Dev\\GPUdev\\Kranker3D\\Kranker3D\\resources\\shaders\\test_vertex.glsl", "D:\\Dev\\GPUdev\\Kranker3D\\Kranker3D\\resources\\shaders\\test_fragment.glsl");
	Texture t("D:\\Dev\\GPUdev\\Kranker3D\\Kranker3D\\resources\\textures\\test.jpg");

	vector<Kranker3D::Vertex> vertices;
	vector<unsigned int> indices;

	Mesh dragon_mesh = setDragoon(vertices, indices);
	Object dragon_obj;
	dragon_obj.getTransform()->translate(glm::vec3(0.0f, -1, 0.0f));

	dragon_obj.getTransform()->rotate(45, glm::vec3(0.0f, 1, 0.0f));
	dragon_obj.getTransform()->scale(glm::vec3(0.25f, 0.25f, 0.25f));

	const float sp = .005f;
	w.setBackgroundColor(0.99, 0.90, 0.94);
	w.setCursorPosCallback(mouse_callback);
	w.setMouseScrollCallback(scroll_callback);

	


	while (w.isOpen())
	{
		w.run();

		dragon_obj.getTransform()->rotate(10 * glfwGetTime(), glm::vec3(0, 1, 0));
		s.setMat4("transform", dragon_obj.getTransform()->getMatrix());
		s.setMat4("view", cam.getView());
		s.setMat4("projection", cam.getProj());
		s.setFloat("iTime", glfwGetTime());
		s.use();
		t.use();
		dragon_mesh.draw();
	}
	// 3. terminate
	s.terminate();
	dragon_mesh.terminate();
}

