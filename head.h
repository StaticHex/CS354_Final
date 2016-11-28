#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <time.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>

// OpenGL library includes
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <debuggl.h>
#include "TGeom.h"
#include "camera.h"
#define PRESS_W key == GLFW_KEY_W && action != GLFW_RELEASE
#define PRESS_A key == GLFW_KEY_A && action != GLFW_RELEASE
#define PRESS_S key == GLFW_KEY_S && action != GLFW_RELEASE
#define PRESS_D key == GLFW_KEY_D && action != GLFW_RELEASE
#define PRESS_LEFT key == GLFW_KEY_LEFT && action != GLFW_RELEASE
#define PRESS_RIGHT key == GLFW_KEY_RIGHT && action != GLFW_RELEASE
#define PRESS_UP key == GLFW_KEY_UP && action != GLFW_RELEASE
#define PRESS_DOWN key == GLFW_KEY_DOWN && action != GLFW_RELEASE
#define PRESS_MIDDLE_BUTTON g_current_button == GLFW_MOUSE_BUTTON_MIDDLE || g_current_button == GLFW_MOUSE_BUTTON_8

bool isGlobal = true;
int g_current_button;
bool g_mouse_pressed;
int window_width = 800, window_height = 600;
std::string window_title = "Sector Map";

std::vector<glm::vec4> obj_vertices;
std::vector<float> vtx_temp;
std::vector<glm::vec4> vtx_normals;
std::vector<Sector> m_data;
std::vector<glm::uvec3> obj_faces;
std::vector<glm::vec4> floor_vertices;
std::vector<glm::vec4> floor_normals;
std::vector<glm::uvec3> floor_faces;
glm::vec4 min_bounds = glm::vec4(std::numeric_limits<float>::max());
glm::vec4 max_bounds = glm::vec4(-std::numeric_limits<float>::max());

// Mouse position vectors
glm::vec2 cPos = glm::vec2(0, 0);
glm::vec2 lPos = glm::vec2(0, 0);
glm::vec2 dV = glm::vec2(0, 0);
float dVl = glm::length(dV);

// Main Loop Vars
glm::vec4 light_position = glm::vec4(1.0f, 5.0f, 1.0f, 1.0f);
int stage = 3;
float aspect = 0.0f;
float theta = 0.0f;

std::shared_ptr<TGeom> g_TGeom;
Camera g_camera;
glm::vec3 AOR;

// VBO and VAO descriptors.
enum { kVertexBuffer, kNormalBuffer, kTempBuffer, kIndexBuffer, kNumVbos };

// These are our VAOs.
enum { kGeometryVao, kFloorVao, kNumVaos };

GLuint g_array_objects[kNumVaos];  // This will store the VAO descriptors.
GLuint g_buffer_objects[kNumVaos][kNumVbos];  // These will store VBO descriptors.

void KeyCallback(GLFWwindow* window,
	int key,
	int scancode,
	int action,
	int mods)
{
	// Note:
	// This is only a list of functions to implement.
	// you may want to re-organize this piece of code.
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	else if (PRESS_W) {
		if (isGlobal) {
			g_camera.setEye(g_camera.getEye() +
				g_camera.getZoomSpeed()*g_camera.getLook());
		}
		else {
			g_camera.setEye(g_camera.getEye() +
				g_camera.getZoomSpeed()*g_camera.getLook());
			g_camera.setCenter(g_camera.getCenter() +
				g_camera.getZoomSpeed()*g_camera.getLook());
		}
	}
	else if (PRESS_S) {
		if (isGlobal) {
			g_camera.setEye(g_camera.getEye() -
				g_camera.getZoomSpeed()*g_camera.getLook());
		}
		else {
			g_camera.setEye(g_camera.getEye() -
				g_camera.getZoomSpeed()*g_camera.getLook());
			g_camera.setCenter(g_camera.getCenter() -
				g_camera.getZoomSpeed()*g_camera.getLook());
		}
	}
	else if (PRESS_A) {
		if (isGlobal) {
			g_camera.setEye(g_camera.getEye() +
				g_camera.getPanSpeed()*g_camera.getRight());
		}
		else {
			g_camera.setEye(g_camera.getEye() +
				g_camera.getPanSpeed()*g_camera.getRight());
			g_camera.setCenter(g_camera.getCenter() +
				g_camera.getPanSpeed()*g_camera.getRight());
		}
	}
	else if (PRESS_D) {
		if (isGlobal) {
			g_camera.setEye(g_camera.getEye() -
				g_camera.getPanSpeed()*g_camera.getRight());
		}
		else {
			g_camera.setEye(g_camera.getEye() -
				g_camera.getPanSpeed()*g_camera.getRight());
			g_camera.setCenter(g_camera.getCenter() -
				g_camera.getPanSpeed()*g_camera.getRight());
		}
	}
	else if (PRESS_UP) {
		if (isGlobal) {
			g_camera.setEye(g_camera.getEye() -
				g_camera.getPanSpeed()*g_camera.getUp());
		}
		else {
			g_camera.setEye(g_camera.getEye() -
				g_camera.getPanSpeed()*g_camera.getUp());
			g_camera.setCenter(g_camera.getCenter() -
				g_camera.getPanSpeed()*g_camera.getUp());
		}
	}
	else if (PRESS_DOWN) {
		if (isGlobal) {
			g_camera.setEye(g_camera.getEye() +
				g_camera.getPanSpeed()*g_camera.getUp());
		}
		else {
			g_camera.setEye(g_camera.getEye() +
				g_camera.getPanSpeed()*g_camera.getUp());
			g_camera.setCenter(g_camera.getCenter() +
				g_camera.getPanSpeed()*g_camera.getUp());
		}
	}
	else if (PRESS_LEFT) {
		g_camera.rotateEye(-g_camera.getLook(), g_camera.getRollSpeed());
	}
	else if (PRESS_RIGHT) {
		g_camera.rotateEye(-g_camera.getLook(), -g_camera.getRollSpeed());
	}
	else if (key == GLFW_KEY_C && action != GLFW_RELEASE) {
		isGlobal = !isGlobal;
	}
	else if (key == GLFW_KEY_1 && action != GLFW_RELEASE) {
		stage = 1;
		for (int i = 0; i < m_data.size(); i++) {
			m_data[i].position.y = 0;
		}
		vtx_normals.clear();
		vtx_temp.clear();
		obj_faces.clear();
		obj_vertices.clear();
		g_TGeom->generate_terrain(m_data, obj_vertices, vtx_normals, obj_faces, vtx_temp);
	} else if (key == GLFW_KEY_2 && action != GLFW_RELEASE) {
		stage = 2;
		for (int i = 0; i < m_data.size(); i++) {
			m_data[i].position.y = 0;
		}
		vtx_normals.clear();
		vtx_temp.clear();
		obj_faces.clear();
		obj_vertices.clear();
		g_TGeom->generate_terrain(m_data, obj_vertices, vtx_normals, obj_faces, vtx_temp);
	}
	else if (key == GLFW_KEY_3 && action != GLFW_RELEASE) {
		stage = 3;
		for (int i = 0; i < m_data.size(); i++) {
			m_data[i].position.y = m_data[i].alt * g_TGeom->blockSize;
		}
		vtx_normals.clear();
		vtx_temp.clear();
		obj_faces.clear();
		obj_vertices.clear();
		g_TGeom->generate_terrain(m_data, obj_vertices, vtx_normals, obj_faces, vtx_temp);
	}
}

void
MousePosCallback(GLFWwindow* window, double mouse_x, double mouse_y)
{
	lPos = cPos;
	cPos = glm::vec2(mouse_x, mouse_y);
	dV = lPos - cPos;
	dVl = glm::length(dV);
	if (!g_mouse_pressed)
		return;
	if (g_current_button == GLFW_MOUSE_BUTTON_LEFT) {
		if (isGlobal) {
			g_camera.rotateEye(g_camera.getUp(), g_camera.getRotationSpeed() * (dV.x / dVl)*.3);
			g_camera.rotateEye(g_camera.getRight(), g_camera.getRotationSpeed() * (dV.y / dVl)*.3);
		}
		else {
			g_camera.setEye(g_camera.getEye() +
				0.2f*(dV.x / dVl)*g_camera.getPanSpeed()*g_camera.getRight());
			g_camera.setCenter(g_camera.getCenter() +
				0.2f*(dV.x / dVl)*g_camera.getPanSpeed()*g_camera.getRight());
			g_camera.setEye(g_camera.getEye() +
				-0.2f*(dV.y / dVl)*g_camera.getPanSpeed()*g_camera.getUp());
			g_camera.setCenter(g_camera.getCenter() +
				-0.2f*(dV.y / dVl)*g_camera.getPanSpeed()*g_camera.getUp());
		}
	}
	else if (g_current_button == GLFW_MOUSE_BUTTON_RIGHT) {
		if (isGlobal) {
			g_camera.setEye(g_camera.getEye() -
				-0.1f*dV.y*g_camera.getZoomSpeed()*g_camera.getLook());
		}
		else {
			g_camera.setEye(g_camera.getEye() -
				-0.1f*dV.y*g_camera.getZoomSpeed()*g_camera.getLook());
			g_camera.setCenter(g_camera.getCenter() -
				-0.1f*dV.y*g_camera.getZoomSpeed()*g_camera.getLook());
		}
	}
	else if (PRESS_MIDDLE_BUTTON) {
		std::cout << std::to_string(g_camera.getLook().z) << "\n";
	}
}

void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	g_mouse_pressed = (action == GLFW_PRESS);
	g_current_button = button;
}