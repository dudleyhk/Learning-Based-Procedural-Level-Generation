/*



*/
#include "Quad.h"

using namespace Rendering::Models;


void Quad::Create()
{
	GLuint vao;
	GLuint vbo;
	GLuint ebo;

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);



	std::vector<VertexFormat> vertices;
	vertices.push_back(VertexFormat(glm::vec3(-0.25, 0.5, 0.0),
									glm::vec4(1, 0, 0, 1), 
					                glm::vec2(1, 1)));
	vertices.push_back(VertexFormat(glm::vec3(-0.25, 0.75, 0.0),
									glm::vec4(0, 0, 0, 1),
									glm::vec2(1, 0)));
	vertices.push_back(VertexFormat(glm::vec3(0.25, 0.5, 0.0), 
									glm::vec4(0, 1, 0, 1), 
									glm::vec2(0, 0)));   
	vertices.push_back(VertexFormat(glm::vec3(0.25, 0.75, 0.0),
									glm::vec4(0, 0, 1, 1), 
									glm::vec2(0, 1)));  


	std::vector<GLuint> indices = 
	{
		0, 1, 3, 
		1, 2, 3
	};


	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices[0], GL_STATIC_DRAW);
	
	// position attributes
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (GLvoid*)0);
	
	// Colour attribue
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (GLvoid*)(offsetof(VertexFormat, VertexFormat::colour)));
	

	// UV attribue
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (GLvoid*)(offsetof(VertexFormat, VertexFormat::uv))); // Offset of : this is where the data starts in the buffer.
	
	glBindVertexArray(0);
	
	
	this->vao = vao;
	this->ebo = ebo;
	this->vbos.push_back(vbo);

}

void Quad::Draw()
{
	glUseProgram(program);
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	//glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

void Quad::Update()
{

}
