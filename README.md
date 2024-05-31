**1. Puzzle.h**


## 데이터 타입 및 구조

1. enum class Jewel
보석의 종류를 정의한다.
값: NONE=-1, RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE, WHITE
2. struct Chain
보석의 연속된 체인을 나타내는 구조체. 시작과 끝 위치를 포함한다.
멤버: Jewel jewel, std::pair<int, int> start, std::pair<int, int> end

**Puzzle 클래스 맴버 변수**

1. int num_rows
퍼즐의 행 수이다.
2. int num_columns
퍼즐의 열 수이다.
3. std::vector<std::vector<Jewel>> array
보드의 상태를 저장하는 2차원 벡터이다.

**Puzzle 클래스 맴버 함수**

1. Puzzle(int num_rows, int num_columns)
생성자, 퍼즐의 크기를 설정하고 초기화한다.
2. bool initialize(const std::string& jewel_list)
주어진 문자열을 사용하여 보드를 초기화한다.
3. void randomize()
보드를 무작위로 초기화한다.
4. bool update()
매치를 찾고 제거한 후 보드를 업데이트한다.
5. bool swapJewels(std::pair<int, int> prev_loc, std::pair<int, int> next_loc)
두 위치의 보석을 교환한다.
6. bool setJewel(std::pair<int, int> loc, Jewel jewel)
특정 위치의 보석을 설정한다.
7. Jewel getJewel(std::pair<int, int> loc) const
특정 위치의 보석을 반환한다.
8. int getNumRows() const
행의 수를 반환한다.
9. int getNumColumns() const
열의 수를 반환한다.
10. static Jewel getJewelType(char letter)
문자를 Jewel 타입으로 변환한다.


11. static char getJewelLetter(Jewel jewel)
Jewel 타입을 문자로 변환한다.

**Private 맴버 함수**

1. void dropJewels()
보석을 아래로 떨어뜨린다.
2. std::vector<std::pair<int, int>> findMatches()
매치된 보석을 찾는다.
3. void removeMatches(const std::vector<std::pair<int, int>>& matches)
매치된 보석을 제거한다.
4. bool areAdjacent(std::pair<int, int> loc1, std::pair<int, int> loc2) const
두 위치가 인접해 있는지 확인한다.


**2. Puzzle.cpp (코드를 더 자세히 보려면 실제 파일 참고)**


## 생성자

1. Puzzle::Puzzle(int num_rows, int num_columns)
퍼즐 보드를 주어진 행과 열의 수로 초기화하고 모든 보석을 NONE으로 설정한다.
**초기화 및 무작위화**
1. bool Puzzle::initialize(const std::string& jewel_list)
문자열을 사용해 보드를 초기화한다. 또한 문자열의 길이가 보드의 크기와 맞지 않으면 false를 반환한다.
2. void Puzzle::randomize()
보드의 각 위치에 무작위로 보석을 할당한다.
**보드 업데이트**
1. bool Puzzle::update()
매치를 찾고 제거하며 보석을 아래로 떨어뜨린다. 또한 매치가 있었는지 여부를 반환한다.
**보석 교환**
1. bool Puzzle::swapJewels(std::pair<int, int> prev_loc, std::pair<int, int> next_loc)
두 위치의 보석을 교환한다. 또한 위치가 인접하지 않거나 유효하지 않으면 false를 반환한다.
**보석 설정 및 가져오기**
1. bool Puzzle::setJewel(std::pair<int, int> loc, Jewel jewel)
특정 위치의 보석을 설정한다.
2. Jewel Puzzle::getJewel(std::pair<int, int> loc) const
특정 위치의 보석을 반환한다.
**보석 타입 변환**
1. Jewel Puzzle::getJewelType(char letter)
문자를 Jewel 타입으로 변환한다.
2. char Puzzle::getJewelLetter(Jewel jewel)
Jewel 타입을 문자로 변환한다.
**매치 찾기 및 제거**
1. std::vector<std::pair<int, int>> Puzzle::findMatches()
보드에서 매치를 찾아 위치를 벡터로 반환한다.
2. void Puzzle::removeMatches(const std::vector<std::pair<int, int>>& matches)
매치된 보석을 NONE으로 설정하여 제거한다.
**보석 떨어뜨리기**
1. void Puzzle::dropJewels()
매치 제거 후 보석을 아래로 떨어뜨리고 빈 자리에 새로운 보석을 무작위로 채운다.
**위치 인접 확인**
1. bool Puzzle::areAdjacent(std::pair<int, int> loc1, std::pair<int, int> loc2) const
두 위치가 인접해 있는지 확인한다.


**3.main_text.cpp (코드를 더 자세히 보려면 실제 파일 참고)**


## 메인 프로그램 함수

1. int getInput()
사용자가 선택할 메뉴 옵션을 입력받는다.
2. int getIndex()
사용자가 선택할 퍼즐 번호를 입력받는다.
3. int checkGetInput(int userInput)
입력된 메뉴 옵션이 유효한지 확인하고 유효하지 않으면 재입력을 받는다.
4. int checkStaticIndex(int userInput)
입력된 퍼즐 번호가 유효한지 확인하고 유효하지 않으면 재입력을 받는다..
5. void printPuzzle(const Puzzle& puzzle)
현재 퍼즐 상태를 콘솔에 출력한다.
1. Puzzle initialize()
퍼즐을 초기화하고 무작위 퍼즐 또는 사전 정의된 퍼즐을 선택하여 설정한다.
2. void randomize(Puzzle& puzzle)
퍼즐을 무작위로 재설정한다.
3. void update(Puzzle& puzzle)
퍼즐을 업데이트한다.(매치를 찾고 제거).
4. bool swap(Puzzle& puzzle, int x1, int y1, int x2, int y2)
퍼즐 보드에서 두 위치의 보석을 교환한다.
5. int main()
메인 게임 루프이다.
사용자가 보석을 교환하고 퍼즐을 업데이트하는 기능을 반복적으로 실행한다.


**4. initialize()**
초기화를 담당하는 부분이다.

먼저 puzzle.h에서 initialize()를 선언했다.

이후 bool 형으로 initialize()를 정의해줬다. 이 코드에서는 문자열을 사용해 보드를 초기화한다. 또한 문자열의 길
이가 보드의 크기와 맞지 않으면 false를 반환한다.

또한 main_text.cpp에서 Puzzle형으로 initialize()를 만들었다. 먼저 puzzle 보드를 8x8 크기로 만든 후 먼저 정
의 해둔 입력들을 받는 코드를 작성했다. 이때 입력호출 함수는 재귀로 만들어서 형식에 맞는 입력이 들어올때 까
지 계속 입력을 요청하는 코드를 구현했다. 이러한 방법을 통하여 편리하게 main 함수에서 초기화를 진행할 수 있
었다.


**5. randomize()**
무작위의 부분을 담당하는 부분이다.

먼저 puzzle.h에서 randomize()를 선언했다.

이후 puzzle.cpp 에서 선언된 randomize()를 정의해줬다.
srand를 이용하여 무작위한 값을 얻을때 사용되는 정석적인 코드를 넣어서 array에 원하는 무작위값이 들어가도
록 설정을 했다.

이후 만들어진 randomize()를 main_text.cpp 파일에서 사용이 편리하게 void형으로 다시 정의해줬다.
이러한 방법을 통하여 편리하게 randomize()를 접근하여 사용할 수 있었다.


**6. update()**
업데이트를 담당하는 부분이다.

먼저 puzzle.h에서 update()를 선언했다.

이후 puzzle.cpp에서 update()를 자세하게 정의를 했다. vector를 사용하여 매치를 찾고 제거하며 보석을 아래로
떨어뜨리게 했다. 또한 매치가 있었는지 여부를 확인하고 반환하는 기능을 구현했다.

이렇게 만들어진 update()를 main_text.cpp 파일에서 사용이 편리하게 void형으로 다시 정의해줬다.
이러한 방법을 통하여 main_text.cpp의 main 함수에서 편리하게 update()를 접근하여 사용할 수 있었다


**7. swap()**
보석을 바꾸는 부분이다

먼저 puzzle.h에서 swapJewels()를 선언했다.

이후 puzzle.cpp에서 swapJewels()를 자세하게 정의를 했다. areAdjacent 함수를 통해서 인접성을 검사하고, 또
한 코드 중간에 보이는 if(prev_loc.first < 0 || prev_loc.first >= num_rows...... ) 영역의 기능으로 유효성까지 검
사하여 교환이 성공적이라면 true를 반환하고 아니라면 false를 반환하도록 설정했다.

이후 만들어진 swap()를 main_text.cpp 파일에서 사용이 편리하게 bool형으로 다시 정의해줬다. Main 함수에서
사용자에게 x1 y1 x2 y2를 입력받고 존재하는 보드 객체와 함께 swap 함수를 호출하면 간편하게 교환이 가능하도
록 구현을 하였다.


**8. Additional feature**
앞선 코드들에서 설명을 했듯 main_text 파일에서 입력을 받을때 재귀 기능을 통하여 오류처리 기능을 넣어봤다.

## 단순하게 입력을 받아 처리를 할 수 있었지만 이러한 기능을 한번 도전해보는 것으로 재귀적인 코드의 구현에 약한

## 약점을 극복해보기 위하여 이러한 기능을 구현해보았다.

위에서 볼 수 있는 것 처럼 checkGetInput 함수에서 입력값이 [ 1 or 2 or 3 ] 이 아니라면 getInput()을
checkGetInput()의 인자로 넣고 값을 반환받는 것으로 재귀적인 기능을 구현했다고 할 수 있다.
똑같은 원리로 pre-defined 퍼즐의 인덱스를 받기 위한 과정에서 재귀적으로 처리를 진행했다.


**9. Conclusion**
결과적으로 작동 코드는 다음과 같다.
**1. 실행중이던 퍼즐 종료**

## 2. 메뉴 출력

## 3. 무작위 퍼즐 (메뉴 1번)

## 4. 미리 입력된 퍼즐 (메뉴 2번의 인덱스 0)


## 5. 미리 입력된 퍼즐 (메뉴 2번의 인덱스 1)

## 6. 미리 입력된 퍼즐 (메뉴 2번의 인덱스 2)

## 7. 미리 입력된 퍼즐 (메뉴 2번의 인덱스 3)

## 8. 틀린 메뉴 번호 선택


## 9. 잘못된 스왑

## 10. 프로그램 종료 ( 메뉴 3번 입력 )

## 11. GUI ( 아래 보라색 세모 4개를 연결하고 사라져서 위의 보석들이 정상적으로 떨어지는 것이다 )

## 고찰 :

## 과제를 시작할때 무엇부터 해야할지, 혹은 오류가 생기면 막대한 파일들 중에서 어떻게 처리해야할지 많은 걱정이

있었다. 실제로도 fltk에서 오류가 생기면서 시작할때부터 막막한 상황에 놓였지만 main_text, 즉 콘솔 영역의 기
능부터 제대로 구현해보자는 다짐으로 컴파일할때 main_text.cpp와 puzzle.cpp 와 puzzle.h 만을 컴파일해서 해
보자고 했다. 이렇게 방향성을 확실히 정하고 나니 확실히 오류 처리부터 시작해서 진행하는 것에 있어서 속도가
붙기 시작했다. 점차 점차 잘 작동되는 것을 보니 상당히 뿌듯하기도 했다. 이후 main_text.cpp가 정상적으로 작동
하는 것을 보고 다시 컴파일 세팅을 원상복구 하고 난 후 main_gui.cpp를 컴파일 하려고 시도하며 fltk로 인해 유
발되는 오류들도 고치고 여러 링크 에러들을 해결하고 나니 위의 11번 GUI의 결과가 잘 화면에 출력되는 것을 보았
다. 물론 이번 과제는 main_text.cpp를 구현하고 puzzle.cpp 와 puzzle.h 를 정상적으로 구동시키기 위한것이 큰
과제였지만 GUI 문제들도 해결해나가며 개인적으로도 프로그래머의 필수적인 자질 중 하나라고 판단하는 문제해
결 능력에 있어 많은 발전이 있었던 것 같았다. 실제로도 이번 과제는 도전적이며 어려웠던 과제라고 생각하며 과
제를 했었는데 이러한 부분에 있어서도 나 자신의 구현 능력도 발전한 것 같아서 뿌듯했다. 논외지만 프로그래밍
전공자와 비전공자의 가장 큰 차이는 구현의 차이가 아니라 코드의 효율의 차이라고들 많이 말한다. 그렇기에 이러
한 점을 숙지하고 나는 “구현할 수 있다”를 넘어서 “최대한 효율적이게 구현할 수 있다”라는 능력을 지닌 프로그래
머를 목표로 하며 프로그래밍 학습에 임하고 싶다는 최종적인 고찰을 하게 된 것 같다.


