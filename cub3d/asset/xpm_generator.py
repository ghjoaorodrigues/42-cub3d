def generate_xpm(width, height, char='xR', hex_color='#FF0000', output_file='solid.xpm'):
    header = f"{width} {height} 1 2"
    color_line = f"{char} c {hex_color}"
    pixel_line = char * width

    xpm = ['/* XPM */']
    xpm.append(f"static char * xpm_image[] = {{")
    xpm.append(f'"{header}",')
    xpm.append(f'"{color_line}",')

    for y in range(height):
        comma = ',' if y < height - 1 else ''
        xpm.append(f'"{pixel_line}"{comma}')

    xpm.append("};")

    with open(output_file, 'w') as f:
        for line in xpm:
            f.write(line + '\n')

    print(f"✅ XPM file generated: {output_file}")

# Example usage
generate_xpm(512, 512, char='xR', hex_color='#FF0000')

