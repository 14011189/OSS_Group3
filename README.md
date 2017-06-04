# OSS_Group3
### 오픈소스SW개론 Project 5### "Shooting Game"
3조  조장 14011189 김현정  15011153 이성령  15011170 안서영  15011185 송다희  

Project
저희 조의 Project 5 소재는 바로 <슈팅게임> 입니다. 
오픈소스 중에서도 게임은 초보 개발자들을 위해서도 무수히 많이 존재하며 활용성이 굉장히 높습니다.
그 중에서도 특히 슈팅게임은 대중적으로 잘 알려져 있어 저희 조원들은 물론 많은 사람들이 쉽고 익숙하게 플레이 할 수 있는 이점을 가졌다고 생각했습니다.
이번 프로젝터를 통해 팀원들끼리 서로 협력하여 기존에 개발되고 있던 슈팅게임 소스의 개발에 참여하고, Github과 Git Bash를 다양한 방법으로 활용해봤습니다.

Programming Language - C

Execution Environment - Code::Blocks 이었으나 코드 개선 후 Visual Studio 2010 에서 실행 가능     

Download Path - Original files: https://github.com/Raffone17/Game-in-C      

License - The MIT License (MIT) Copyright (c) 2015 Raffone17

Play Method
이 게임은 Visual Studio를 통해 실행할 수 있으며 소스파일에서 condition.c인 기본파일을 추가하면 게임이 실행됩니다.
1번을 눌러 new game이 시작되면 좌, 우 조종키를 사용해 적객체의 미사일을 피하고 스페이스 바를 사용해 총알을 발사합니다. 
적객체를 없애면 레벨이 오르며 스테이지가 바뀝니다. 모든 스테이지를 클리어하면 게임이 종료됩니다.

Improved Point
1. 조작키 변경
기존의 4,5,6인 조종키를 방향키로 변경했습니다.
2. 소스코드 분리
main.c 파일을 함수 쓰임별로 나눠주었습니다.
3. 게임화면의 커서 출력 변경
커서가 화면에 나타나지 않도록 커서의 출력을 없앴습니다.
4. 함수명, 변수명 변경
함수와 변수명을 이탈리아어에서 영어로 변경해줬습니다.
5. 아이템 추가
level에 따라 조종키가 반대로 작동하는 아이템을 추가했습니다.
