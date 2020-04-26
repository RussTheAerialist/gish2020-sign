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

	vec3 red = vec3(1.0, .3, .3);
	vec3 orange = vec3(0.9725, 0.5843, 0.0784);
	vec3 yellow = vec3(1., 1., 0.);
	vec3 green = vec3(0., 1., 0.);
	vec3 blue = vec3(.3, .3, 1.);
	vec3 purple = vec3(0.8824, 0.0, 1.0);
	float mixValue = sin(distance(st + time , vec2(0., 1.)));

	vec3 color = mix(purple, red, smoothstep(0, .15, mixValue));
			 color = mix(color, orange, smoothstep(.15, .3, mixValue));
			 color = mix(color, yellow, smoothstep(.3, .45, mixValue));
			 color = mix(color, green, smoothstep(.45, .6, mixValue));
			 color = mix(color, blue, smoothstep(.6, 75., mixValue));
			 color = mix(color, purple, smoothstep(.75, 1., mixValue));
	vec4 texel = texture(tex0, texcoordvarying);

	outputColor = vec4(color * texel.a, texel.a);
	// outputColor = vec4(color, 1.);
}
