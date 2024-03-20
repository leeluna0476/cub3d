# perpWallDist 구하기
플레이어부터 시작하는 광선 자체의 길이로 벽을 그린다면 실제로는 수평의 벽이어도 모든 광선의 길이가 다르기 때문에 벽이 앞으로 볼록하게 보이는 *어안렌즈* 현상이 발생할 수 있다.

이를 보정하기 위해서 카메라 평면으로부터 광선이 충돌한 지점까지의 수직선으로 일정한 길이를 구해야 한다.

예: $x$축과 수직인 선에 닿았을 경우

$perpWallDist = \frac{sideDist_y - playerPos_y}{rayDir_y}$

예: $y$축과 수직인 선에 닿았을 경우

$perpWallDist = \frac{sideDist_x - playerPos_x}{rayDir_x}$

---

$perpWallDist$ *유도*

$playerPos$에서 $x$축과 수평인 선을 긋고 충돌지점과 수직인 선을 그어 $b$를 가정한다. (선 $l1$)

그리고 $playerDir$(유저의 방향벡터)의 끝점에서 카메라평면과 수평인 선($l2$)을 긋고 $sideDist$와의 교점에서부터 $l1$과 수직인 선을 긋는다.

이렇게 만들어진 두 삼각형은 닮음이고, 아래와 같은 비례식을 세울 수 있다.

$rayDir : sideDist = rayDir_y : b$

$l2$와 $sideDist$의 교점에서 카메라 평면과 수직인 선(유저의 방향벡터)과 $rayDir$, $sideDist$와 충돌지점에서부터 카메라 평면과 수직인 선($perpWallDist$)으로 만들어진 두 삼각형은 닮음이고, 아래와 같은 비례식을 세울 수 있다.

$rayDir : sideDist = playerDir : perpWallDist$

두 비례식을 보면 좌변이 같다. 우변끼리 이어 다음의 식을 정립한다.

$rayDir_y : b = playerDir : perpWallDist$

$perpWallDist = \frac{b \times playerDir}{rayDir_y}$

우리는 $b$를 알 수 있다. 플레이어의 위치에서 광선이 부딪힌 지점까지의 높이가 될 것이다.

$b = sideDist_y - playerPos_y$

최종적으로 아래와 같이 구할 수 있다.

$perpWallDist = \frac{(sideDist_y - playerPos_y) \times playerDir}{rayDir_y}$

$y$**축에서 수직인 선에 닿았을 경우에도 동일하게 구할 수 있다.**
