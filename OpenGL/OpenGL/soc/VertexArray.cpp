#include"VertexArray.h"
#include"Renderer.h"
#include"VertexBufferLayout.h"

VertexArray::VertexArray()
{
	GLCALL(glGenVertexArrays(1, &m_RendererID));
	GLCALL(glBindVertexArray(m_RendererID));
}

VertexArray::~VertexArray()
{
	GLCALL(glDeleteVertexArrays(1, &m_RendererID));
}

void VertexArray::Addbuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
	Bind();
	vb.bind();
	const auto& elements = layout.GetElements();
	unsigned int offset = 0;
	for (unsigned int i = 0; i < elements.size(); i++)
	{
		const auto& element = elements[i];
		glEnableVertexAttribArray(i);//������indexָ����ͨ�ö�����������
		glVertexAttribPointer(i, element.count, element.type, 
			element.normalized, layout.GetStride(), (const void*)offset);//ָ����index����ͨ�ö������������λ�ú����ݸ�ʽ
		offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
	}
	
}

void VertexArray::Bind() const
{
	GLCALL(glBindVertexArray(m_RendererID));
}
void VertexArray::Unbind() const
{
	GLCALL(glBindVertexArray(0));
}