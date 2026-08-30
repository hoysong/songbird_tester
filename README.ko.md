# Songbird Tester

[English](./README.md) | [한국어](./README.ko.md)

## 프로젝트 소개

Songbird Tester는 여러 42 과제를 개발하면서 만든 경량 테스트 도구
모음입니다. 개발 중 반복되는 검사를 자동화하여 같은 명령과 입력을 매번
직접 실행하지 않고도 오류를 재현하고 결과를 확인할 수 있도록 만들었습니다.

프로그램 출력 비교, 여러 버퍼 크기 테스트, Valgrind 메모리 검사, Minishell에
스크립트 입력과 시그널 전송, Cub3D 파서 테스트 등의 도구를 포함합니다.

## 포함된 도구

| 도구 | 용도 |
| --- | --- |
| `get_next_line_tester/` | 여러 `BUFFER_SIZE` 값으로 Get Next Line을 컴파일·실행하고 출력 비교, Valgrind 검사 및 Norminette 검사를 수행합니다. |
| `minishell_test_builder_1.5/` | Minishell에 전달할 입력을 구성하고 파일 디스크립터별로 Bash와 Minishell의 동작을 비교합니다. |
| `cub3d_pars_tester/` | 설정한 맵 디렉터리의 Cub3D 파서 테스트를 실행하며 필요하면 Valgrind 검사를 함께 수행합니다. |
| `compile.sh` | 간단한 Push Swap 테스트 케이스를 실행하고 명령 수, `checker_linux` 결과 및 Valgrind 실행 결과를 확인합니다. |

## 요구 사항

각 도구는 다음 환경 중 일부를 사용합니다.

- Linux 또는 호환 가능한 셸 환경
- Bash
- `cc`, `clang` 등의 C 컴파일러
- GNU Make
- Valgrind
- Get Next Line 스타일 검사용 Norminette
- 테스트할 42 프로젝트와 필요한 소스 파일

일부 스크립트는 상대 경로와 프로젝트별 실행 파일명을 사용합니다. 실행하기
전에 각 스크립트의 상단 또는 하단에 있는 설정 변수를 확인하세요.

## 사용 방법

선택한 테스터가 요구하는 상대 경로에 맞춰 대상 프로젝트의 내부 또는 인접한
위치에 저장소를 복제합니다.

```bash
git clone https://github.com/hoysong/songbird_tester.git
```

### Get Next Line

Get Next Line 테스터는 스크립트에 설정된 상대 경로에서
`get_next_line.c`, `get_next_line_utils.c`, `get_next_line.h`를
찾습니다.

```bash
cd get_next_line_tester
bash run.sh
```

`BUFFER_SIZE` 1부터 12까지 구현을 반복해서 컴파일하고, 생성된 출력과
기대 결과를 비교합니다. Valgrind 로그와 Norminette 오류도 함께 검사하며,
상세한 출력 차이는 생성되는 `trace` 파일에 기록합니다.

### Minishell Test Builder

`minishell_test_builder_1.5/main.c`를 편집하여 대상 셸에 전달할 입력
순서를 작성한 다음 테스트 프로그램을 빌드합니다.

```bash
cd minishell_test_builder_1.5
bash compile.sh
./a.out
```

테스트 빌더는 파일 디스크립터별로 Bash와 Minishell의 출력을 비교할 수
있으며, 스크립트 시나리오 도중 `SIGINT`와 `SIGQUIT`을 전송할 수
있습니다.

### Cub3D Parser Tester

`cub3d_pars_tester/test.sh`의 `prog_name`과 테스트 디렉터리를 설정한
다음 실행합니다.

```bash
cd cub3d_pars_tester
bash test.sh
```

파서 테스트를 일반 실행 또는 Valgrind를 통한 실행으로 구성할 수 있습니다.
맵 유효성 판단 기준은 구현에 따라 다를 수 있으므로 제공된 테스트 케이스를
확인하고 대상 파서에 맞게 조정하세요.

### Push Swap Quick Check

루트의 `compile.sh`는 `my_libft/libft.a`를 포함한 특정 프로젝트 구조와
저장소에 포함된 Linux용 Checker를 전제로 합니다.

```bash
bash compile.sh
```

대상 프로젝트의 구조가 다르면 컴파일 명령과 테스트 인자를 수정해서
사용하세요.

## 구현 범위와 제한사항

이 도구들은 개발 중 반복적인 검사를 돕기 위한 것이며, 과제의 모든 요구사항을
판정하는 공식 검증기가 아닙니다. 테스터 자체를 필요 이상으로 복잡하게 만들지
않고 메인 프로젝트 개발에 집중할 수 있도록 실용적인 범위의 자동화를
목표로 합니다.

Get Next Line 테스터에는 실행 시간 제한 기능이 적용되어 있지 않습니다.
테스트가 비정상적으로 오래 지속된다면 대상 구현에서 무한루프가 발생했는지
확인하고 프로세스를 직접 종료하세요. 이는 자동 진단 대상으로 포함하지 않은
의도적인 구현 범위입니다.

구현 방식의 차이에 따라 테스트 케이스와 기대 결과를 조정해야 할 수도
있습니다. 최종적이고 엄격한 검증이 필요한 경우에는 별도의 테스터나 수동
검증을 함께 사용하세요.
