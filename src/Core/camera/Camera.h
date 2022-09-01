
	using vec3 = glm::vec3;
	using mat4 = glm::mat4;


	const float YAW = -90.0f;
	const float PITCH = 0.0f;
	const float CAMERASPEED = 5.0f;
	const float SENSITIVITY = 0.1f;
	const float FOV = 45.0f;

	class Camera
	{
	public:
		// Constructor
		Camera(vec3 position = vec3(0.0f, 0.0f, 0.0f), 
			vec3 worldup = vec3(0.0f, 1.0f, 0.0f));

		Camera(float posX = 0.0f, float posY = 0.0f, float posZ = 0.0f, 
			float worldupX = 0.0f, float worldupY = 1.0f, float worldupZ = 0.0f);

		
		mat4 getViewMatrix()
		{
			return glm::lookAt(m_Position, m_Position + m_Front, m_Up);
		}

		// Camera Movement
		inline void MoveForward(float deltaTime);
		inline void MoveBackward(float deltaTime);
		inline void MoveLeft(float deltaTime);
		inline void MoveRight(float deltaTime);
		inline void MoveUp(float deltaTime);
		inline void MoveDown(float deltaTime);

		// Camera View Movement
		void LookAround_Callback(double xPos, double yPos, float windowSizeX, float windowSizeY);

		// Camera Field Of View Change by Mouse Scroll
		void ScrollFOV_Callback(double yOffset);

		// Get
		inline vec3 GetPosition()               const { return m_Position; }
		inline vec3 GetFrontVec()               const { return m_Front; }
		inline vec3 GetUpVec()                  const { return m_Up; }
		inline vec3 GetRightVec()               const { return m_Right; }
											    			   
		inline float GetCameraYaw()             const { return m_Yaw; }
		inline float GetCameraPitch()           const { return m_Pitch; }
											    			   
		inline float GetCameraSpeed()           const { return m_CameraSpeed; }
		inline float GetMouseSensitivity()      const { return m_MouseSensitivity; }
		inline float GetCameraFieldOfView()     const { return m_Fov; }

		// Set
		inline float SetCameraSpeed(float speed)				{ m_CameraSpeed = speed; }
		inline float SetMouseSensitivity(float sensitivity)		{ m_MouseSensitivity = sensitivity; }
		inline float SetCameraFieldOfView(float fov)			{ m_Fov = fov; }

	private:
		vec3 m_Position;
		vec3 m_Front;
		vec3 m_Up;
		vec3 m_Right;
		vec3 m_WorldUp;

		float m_Yaw = YAW;
		float m_Pitch = PITCH;

		float m_CameraSpeed = CAMERASPEED;
		float m_MouseSensitivity = SENSITIVITY;
		float m_Fov = FOV;

		// calculate the current vector of camera
		void UpdateCameraVectors();
	};

