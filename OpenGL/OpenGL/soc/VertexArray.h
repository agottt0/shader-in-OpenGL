#pragma once

#include"VertexBuffer.h"

class VertexBufferLayout;

class VertexArray
{
private:
	unsigned int m_RendererID;
public:
	VertexArray();
	~VertexArray();

	void Addbuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

	void Bind() const;
	void Unbind() const;
};