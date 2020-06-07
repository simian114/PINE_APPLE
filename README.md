# :pineapple: PINE APPLE SHELL
***minishell by [gmoon](https://github.com/moon9ua) and [sanam](https://github.com/simian114).***<br>
***@ 42 Seoul***<br>
***(2020. 05. 17. ~ 2020. 05. 28.)***

![GIF](GIF.gif)
-----

## 왜 탭, 화살표 등은 입력이 안될까?
이 부분을 해결하기 위해서는 termcap 라이브러리를 사용해야한다.  
termpcap은 terminal + capability의 약자로  
대충 터미널의 기능을 사용하게 해주는 라이브러리로 알면된다.  
(https://github.com/simian114/minishell_with_termcap)[minishell_with_termcap] 이 레파지토리에서  
termcap 라이브러리를 활용해서 입력을 받아오는 함수를 구현하는 중...  
나중에 이 함수 다 구현되면 minishell에 적용할 예정이다.
