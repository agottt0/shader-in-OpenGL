#include"Renderer.h"
#include"IndexBuffer.h"

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
    : m_Count(count)
{
    GLCALL(glGenBuffers(1, &m_RenderID));//���ػ������е� n ����������������
    GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RenderID));//������������󶨵�ָ���Ļ������󶨵�
    GLCALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));//Ϊ��ǰ�󶨵�Ŀ��Ļ��������󴴽��µ����ݴ洢��
}

IndexBuffer::~IndexBuffer()
{
    GLCALL(glDeleteBuffers(1, &m_RenderID));
}

void IndexBuffer::bind() const
{
    GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RenderID));
}

void IndexBuffer::unbind() const
{
    GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}