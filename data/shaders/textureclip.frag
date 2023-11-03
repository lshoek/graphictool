// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#version 450 core

uniform UBO
{
	vec3 color;
	float alpha;
} ubo;

in vec3 pass_Uvs;

out vec4 out_Color;

uniform sampler2D colorTexture;

const float EPSILON = 0.001;

void main(void)
{
	// Sample colorTexture
	vec4 texture_color = texture(colorTexture, pass_Uvs.xy);
	if (texture_color.a <= EPSILON)
		discard;

	// Set output color
	out_Color = vec4(texture_color.rgb * ubo.color, texture_color.a * ubo.alpha); 
}
