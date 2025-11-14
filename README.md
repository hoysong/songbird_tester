+ 테스터기가 이상하다면 여러분이 맞습니다.
+ songbird_tester 레포지토리를 여러분의 과제 디렉토리 안에 넣어주세요.
+ place tester repository in your project dir.

# get_next_line tester
+ gnl 테스터는.. 안정적이지 못하니 다른 테스터를 권장합니다.
+ this tester is trash. use other tester.
+ get next line  tester 는 무한루프를 탈출하지 못합니다.
+ 이상하게 오래걸리는 테스트케이스가 있다면 get next line에서 무한루프가 발생한 것입니다.

# minishell_tester_builder
+ 미니쉘 테스터 빌더입니다.
+ this is minishell tester builder
+ 테스터 레포지토리를 과제 디렉토리 안에서 클론하면 됩니다.
+ clone this repository in your project directory.
+ main.c를 편집하여 원하는 입력을 보낼 수 있습니다.
+ by modifying main.c can send input.
+ main.c를 양식에 맞춰 작성한 후, bash compile.sh를 통해서 a.out 실행파일을 생성할 수 있습니다.
+ after done modifying, type 'bash compils.sh' to make a.out executable file.
+ bash와 minishell의 출력을 fd별로 출력합니다.
+ this shows output of minishell and bash.
+ bash는 대화형모드 옵션으로 실행됩니다.
+ bash will execute with interactive mode.
+ "SIGQUIT\n", "SIGINT\n"를 통해서 minishell에 시그널을 보낼 수 있습니다.
+ you can send signal with "SIGNAL\n", "SIGINT\n" to your minishell.
+ (see main.c)

# cub3D_pars_tester
+ cub3d 파싱 테스터입니다.
+ 원한다면 test.sh 파일을 수정하여 실행할 수 있습니다.
+ 파일 하단의 양식을 통해 테스트 파일의 위치를 수정할 수 있습니다.
+ normal_test를 실행하여 일반 테스트를 실행할 수 있습니다.
+ leak_test를 실행하여 누수 체크를 할 수 있습니다.
+ 맵의 유효성 체크 로직은 구현에 따라 다를 수 있습니다.
+ 해당 경우에는 직접 유효한/유효하지 않은 맵을 모아놓은 디렉토리를 따로 만드시는 것을 추천드립니다.
+ prog_name="a.out"을 수정하여 실행파일의 위치를 지정할 수 있습니다.
