#include "get_next_line.h"

static char *extract_line(char *buffer) {
    int i = 0;
    char *line;

    while (buffer[i] && buffer[i] != '\n')
        i++;
    line = (char *)malloc(i + 2);
    if (!line)
        return NULL;
    i = 0;
    while (buffer[i] && buffer[i] != '\n') {
        line[i] = buffer[i];
        i++;
    }
    if (buffer[i] == '\n') {
        line[i] = '\n';
        i++;
    }
    line[i] = '\0';
    return line;
}

static char *read_from_fd(int fd, char *buffer) {
    char temp[BUFFER_SIZE + 1];
    int bytes_read;

    while (!ft_strchr(buffer, '\n')) {
        bytes_read = read(fd, temp, BUFFER_SIZE);
        if (bytes_read <= 0)
            return buffer[0] ? buffer : NULL;
        temp[bytes_read] = '\0';
        buffer = ft_strjoin(buffer, temp);
        if (!buffer)
            return NULL;
    }
    return buffer;
}

char *get_next_line(int fd) {
    static char buffer[BUFFER_SIZE + 1];
    char *line;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    if (!buffer[0])
        read(fd, buffer, BUFFER_SIZE);
    buffer[BUFFER_SIZE] = '\0';
    if (!(buffer == read_from_fd(fd, buffer)))
        return NULL;
    line = extract_line(buffer);
    ft_clean_buffer(buffer, ft_strlen(line));
    return line;
}
