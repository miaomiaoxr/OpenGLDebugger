#pragma once

#include <glad/glad.h>

#include <string>

class Shader {
  public:
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    ~Shader();

    void use() const;

    Shader(const Shader&) = delete;
    Shader& operator=(const Shader&) = delete;

  private:
    unsigned int m_id;

    static std::string readFile(const std::string& path);
    static unsigned int compile(unsigned int type, const std::string& source);
};
