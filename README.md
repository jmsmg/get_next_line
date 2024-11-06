
# get_next_line

`get_next_line`은 파일 디스크립터를 사용하여 텍스트 파일의 내용을 한 줄씩 읽어오는 함수입니다. 이 함수는 버퍼를 이용해 한 번에 파일에서 데이터를 읽고, 개행 문자가 나오거나 파일의 끝에 도달할 때까지 데이터를 누적하여 반환합니다.

## 목차
- [get\_next\_line](#get_next_line)
	- [목차](#목차)
	- [프로젝트 개요](#프로젝트-개요)
	- [함수 개요](#함수-개요)
	- [구현 세부 사항](#구현-세부-사항)
	- [설치 방법](#설치-방법)
	- [사용 방법](#사용-방법)

## 프로젝트 개요

이 프로젝트는 파일을 한 줄씩 읽는 `get_next_line` 함수를 구현하는 것을 목표로 합니다. `get_next_line`은 파일을 다루는 프로그램이나 데이터 스트림을 처리할 때 유용하며, 다양한 파일 읽기 상황에서 사용될 수 있습니다.

## 함수 개요

```c
int get_next_line(int fd, char **line);
```

- **매개변수**:
  - `fd`: 읽어올 파일의 파일 디스크립터.
  - `line`: 파일에서 읽은 문자열을 저장할 포인터. `line`은 개행 문자까지의 문자열을 가리키며, `get_next_line` 호출마다 새로 할당되어야 합니다.

- **반환값**:
  - **1**: 한 줄을 성공적으로 읽은 경우
  - **0**: 파일의 끝에 도달한 경우
  - **-1**: 에러가 발생한 경우

## 구현 세부 사항

- **버퍼 크기**: `get_next_line`은 `BUFFER_SIZE`를 사용하여 한 번에 읽을 데이터 크기를 결정합니다. 이 값을 적절히 설정하여 메모리 사용을 조절할 수 있습니다.
- **동적 메모리 할당**: `get_next_line`은 `malloc`을 사용하여 매 호출마다 새로운 문자열을 할당하고 반환합니다. 이를 통해 메모리 누수를 방지하고 안정적으로 파일의 한 줄씩을 처리할 수 있습니다.
- **여러 파일 디스크립터 처리**: 이 함수는 동시에 여러 파일 디스크립터를 관리할 수 있어, 여러 개의 파일을 동시에 읽어오는 것이 가능합니다.

## 설치 방법

1. 이 프로젝트의 파일들을 클론합니다.
    ```bash
    git clone https://github.com/jmsmg/get_next_line.git
    cd get_next_line
    ```

2. 필요한 파일을 컴파일합니다.
  - 버퍼 크기는 구애 받지 않습니다.
    ```bash
    gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c
    ```

## 사용 방법

`get_next_line` 함수는 다음과 같이 사용할 수 있습니다.

```c
#include "get_next_line.h"
#include <fcntl.h>  // 파일 디스크립터 함수
#include <stdio.h>  // printf

int main(void) {
    int fd = open("example.txt", O_RDONLY);
    char *line;
    
    while (get_next_line(fd, &line) > 0) {
        printf("%s
", line);
        free(line);
    }
    free(line); // 마지막 라인도 해제
    close(fd);
    return 0;
}
```