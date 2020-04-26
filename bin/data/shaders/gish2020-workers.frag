#version 150

uniform sampler2DRect tex0;
in vec2 texcoordvarying;
out vec4 outputColor;
uniform vec2 u_resolution;
uniform float time;

vec2 rationalize() {
	vec2 sq = vec2(u_resolution.x, u_resolution.x);
	float sqo = (u_resolution.y - u_resolution.x) / u_resolution.y;
	vec2 st = (gl_FragCoord.xy) / sq;
	st.y -= sqo;

	return st;
}

void main() {
	vec2 st = rationalize();

	vec3 color1 = vec3(1.0, .3, .3);
	vec3 color2 = vec3(.3, .3, 1.);
	// float mixValue = distance(st * sin(time) / 5., vec2(0., 1.));
	float mixValue = sin(distance(st + time * 5., vec2(0., 1.)));

	vec3 color = mix(color1, color2, mixValue);
	vec4 texel = texture(tex0, texcoordvarying);

	outputColor = vec4(color * texel.a, texel.a);
	// outputColor = texel;
	// outputColor = vec4(color, 1.);
}
