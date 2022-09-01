#include "Camera.h"


	/******************************************
	* Constructor
	*******************************************/
	Camera::Camera(vec3 position, vec3 worldup)
		: m_Front(vec3(0.0f, 0.0f, -1.0f)), 
		  m_Position(position), 
		  m_WorldUp(worldup)
	{
		UpdateCameraVectors();
	}

	Camera::Camera(float posX, float posY, float posZ, float worldupX, float worldupY, float worldupZ)
		: m_Front(vec3(0.0f, 0.0f, -1.0f)), 
		  m_Position(vec3(posX, posY, posZ)), 
		  m_WorldUp(vec3(worldupX, worldupY, worldupZ))
	{
		UpdateCameraVectors();
	}


	/********************************************
	* Camera Movement
	*********************************************/
	void Camera::MoveForward(float deltaTime)
	{
		m_Position += m_Front * (m_CameraSpeed * deltaTime);
	}

	inline void Camera::MoveBackward(float deltaTime)
	{
		m_Position -= m_Front * (m_CameraSpeed * deltaTime);
	}

	inline void Camera::MoveLeft(float deltaTime)
	{
		m_Position -= glm::normalize(glm::cross(m_Front, m_Up)) * (m_CameraSpeed * deltaTime);
	}

	inline void Camera::MoveRight(float deltaTime)
	{
		m_Position += glm::normalize(glm::cross(m_Front, m_Up)) * (m_CameraSpeed * deltaTime);
	}

	void Camera::MoveUp(float deltaTime)
	{
		m_Position += m_Up * (m_CameraSpeed * deltaTime);
	}

	void Camera::MoveDown(float deltaTime)
	{
		m_Position -= m_Up * (m_CameraSpeed * deltaTime);
	}

	/********************************************
	* use in glfw callback register -------- Look Around
	**********************************************/
	bool FirstMouse = true;
	float LastPosX = 0.0f;
	float LastPosY = 0.0f;
	float XOffset = 0.0f;
	float YOffset = 0.0f;
	void Camera::LookAround_Callback(double xPos, double yPos, float windowSizeX, float windowSizeY)
	{
		float MousePosX = static_cast<float>(xPos);
		float MousePosY = static_cast<float>(yPos);

		/* if click the window firstly */
		if (FirstMouse)
		{
			/* set the lastPos as click point */
			LastPosX = MousePosX;
			LastPosY = MousePosY;
			FirstMouse = false;
		}

		XOffset = MousePosX - LastPosX;
		YOffset = LastPosY - MousePosY;

		m_Yaw += XOffset * m_MouseSensitivity;
		m_Pitch += YOffset * m_MouseSensitivity;

		/* limite range of pitch angle */
		if (Pitch > 89.0f)
		{
			Pitch = 89.0f;
		}
		if (Pitch < -89.0f)
		{
			Pitch = -89.0f;
		}

		/* Update front vector */
		UpdateCameraVectors();

		LastPosX = MousePosX;
		LastPosY = MousePosY;
	}

	/********************************************
	* use in glfw callback register -------- restrict the fov scale
	**********************************************/
	void Camera::ScrollFOV_Callback(double yOffset)
	{
		m_Fov -= static_cast<float>(yOffset);
		if (m_Fov > FOV)
		{
			m_Fov = FOV;
		}
		if (m_Fov < 1.0f)
		{
			m_Fov = 1.0f;
		}
	}


	/********************************************
	* For Camera init and front/Right/up vector change in Look around movement
	*********************************************/
	void Camera::UpdateCameraVectors()
	{
		glm::vec3 front;
		front.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
		front.y = sin(glm::radians(m_Pitch));
		front.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
		m_Front = glm::normalize(front);
		/* schimidt orthogonalization */
		m_Right = glm::normalize(glm::cross(m_Front, m_WorldUp));
		m_Up = glm::normalize(glm::cross(m_Right, m_Front));
	}
