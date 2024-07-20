#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void) {
	int fd, n;
	off_t start, cur;
	char buf[256]; // 255����Ʈ

	fd = open("linux.txt", O_RDONLY);
	if (fd == -1) {
		perror("Open linux.txt");
		exit(1);
	}

	start = lseek(fd, 0, SEEK_CUR);
	n = read(fd, buf, 255);
	buf[n] = '\0';
	printf("Offset start = %d, Read Str = %s, n = %d\n", (int)start, buf, n);
	// ������ġ, ���� ����, �� ���� �о����� ���
	cur = lseek(fd, 0, SEEK_CUR); // ���� ��ġ �޾ƿ�
	printf("Offset cur = %d\n", (int)cur);

	start = lseek(fd, 6, SEEK_SET); // ���� ������ 6����Ʈ ������ �̵�
	n = read(fd, buf, 255); // 255����Ʈ �о ���
	buf[n] = '\0';
	printf("Offset start = %d, Read Str = %s", (int)start, buf);
	// 6��°���� ������ Linux �� ���ư��� System Programming�� ���
	close(fd);
		
	return 0;
}
