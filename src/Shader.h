#pragma once

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>

class Shader {
  public:
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    ~Shader();

    void use() const;

    Shader(const Shader&) = delete;
    Shader& operator=(const Shader&) = delete; 
    void setMat4(const std::string& name, const glm::mat4& mat);

  private:
    unsigned int m_id;

    static std::string readFile(const std::string& path);
    static unsigned int compile(unsigned int type, const std::string& source);
};
