#version 460 core

uniform uint frag_color;

out vec4 color;

vec4 rgba() {
	return vec4(
			frag_color >> 24 & 0xff,
			frag_color >> 16 & 0xff,
			frag_color >> 8 & 0xff,
			frag_color & 0xff,
			) / 255.0f;
}

void main() {
	color = rgba();
}
