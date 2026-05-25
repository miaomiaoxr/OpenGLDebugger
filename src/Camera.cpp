#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>

glm::mat4 Camera::GetViewMatrix() {
    return glm::lookAt(Position, Position + Front, Up);
}

Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
    : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(2.5f), MouseSensitivity(0.1f) {
    Position = position;
    WorldUp = up;
    Yaw = yaw;
    Pitch = pitch;
    UpdateCameraVectors();
}

void Camera::ProcessKeyboard(CameraMovement direction, float deltaTime) {
    float velocity = MovementSpeed * deltaTime;

    if (direction == CameraMovement::Forward) {
        Position += Front * velocity;
    }

    if (direction == CameraMovement::Backward) {
        Position -= Front * velocity;
    }

    if (direction == CameraMovement::Left) {
        Position -= Right * velocity;
    }

    if (direction == CameraMovement::Right) {
        Position += Right * velocity;
    }
}

void Camera::ProcessMouseMovement(float xOffset, float yOffset) {
    xOffset *= MouseSensitivity;
    yOffset *= MouseSensitivity;

    Yaw += xOffset;
    Pitch += yOffset;

    if (Pitch > 89.0f) {
        Pitch = 89.0f;
    }

    if (Pitch < -89.0f) {
        Pitch = -89.0f;
    }

    UpdateCameraVectors();
}

void Camera::UpdateCameraVectors() {
    glm::vec3 front;
    front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    front.y = sin(glm::radians(Pitch));
    front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));

    Front = glm::normalize(front);
    Right = glm::normalize(glm::cross(Front, WorldUp));
    Up = glm::normalize(glm::cross(Right, Front));
}