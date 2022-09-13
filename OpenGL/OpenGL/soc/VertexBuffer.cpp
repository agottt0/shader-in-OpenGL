#include"Renderer.h"
#include"VertexBuffer.h"

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
    GLCALL(glGenBuffers(1, &m_RenderID));//���ػ������е� n ����������������
    GLCALL(glBindBuffer(GL_ARRAY_BUFFER, m_RenderID));//������������󶨵�ָ���Ļ������󶨵�
    GLCALL(glBufferData(GL_ARRAY_BUFFER, 4 * 4 * sizeof(float), data, GL_STATIC_DRAW));//Ϊ��ǰ�󶨵�Ŀ��Ļ��������󴴽��µ����ݴ洢��
}

VertexBuffer::~VertexBuffer()
{
    GLCALL(glDeleteBuffers(1, &m_RenderID));
}

void VertexBuffer::bind() const
{
    GLCALL(glBindBuffer(GL_ARRAY_BUFFER, m_RenderID));
}

void VertexBuffer::unbind() const 
{
    GLCALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
}