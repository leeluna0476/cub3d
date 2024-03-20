# 직선 그리기 (DDA 알고리즘)
광선이 처음으로 만나는 격자(초기 sideDist)에 한 칸 이동할 때의 거리(deltaDist)를 더해가며 한 칸씩 이동하다 보면 정확하게 한 칸씩 이동하면서 벽에 부딪히는지 감지할 수 있다.

$sideDist_x, deltaDist_x$ - $x$를 따라 이동하는 거리.
$sideDist_y, deltaDist_y$ - $y$를 따라 이동하는 거리.

## deltaDist 구하기

$deltaDist_x = |\frac{|rayDir|}{rayDir_x}|$

$deltaDist_y = |\frac{|rayDir|}{rayDir_y}|$

---

$deltaDist$ ***유도***

예: $deltaDist_y$
- $deltaDist_y$의 시작점에서 $y$축에 수직인 직선과, 끝점에서 $x$축에 수직인 직선을 그어 교차점을 찍으면 삼각형이 만들어지는데, 이 삼각형은 광선의 방향벡터를 가지고 마찬가지로 각 축에 수직인 직선들을 그었을 때 만들어지는 삼각형과 닮음이다.
- 이를 가지고 비례식을 세울 수 있다.
- $deltaDist_y$의 끝점에서 $x$축에 수직인 직선은 길이가 반드시 1이다.
  - $y$축에 수직인 직선은 길이를 알 수 없으므로 $a$라고 표기한다.

$rayDir_x : rayDir_y = a : 1$

$a = \frac{rayDir_x}{rayDir_y}$

$a$의 길이를 구했다. 그렇다면 $deltaDist_y$의 길이를 구해보자.
$adjacent$와 $opposite$의 길이를 알고 있으니 피타고라스의 정리를 사용해서 $hypotenuse$가 되는 $deltaDist_y$의 길이를 구할 수 있다.

$deltaDist_y = |\sqrt(a^2 + 1^2)|$

$deltaDist_y = |\sqrt(\frac{rayDir_x}{rayDir_y}^2 + 1^2)|$

$deltaDist_y = |\sqrt(\frac{rayDir_x^2}{rayDir_y^2} + \frac{rayDir_y^2}{rayDir_y^2})|$

$deltaDist_y = |\frac{\sqrt(rayDir_x^2 + rayDir_y^2)}{\sqrt(rayDir_y^2)}|$

$deltaDist_y = |\frac{\sqrt(rayDir_x^2 + rayDir_y^2)}{rayDir_y}|$

최종적으로, 아래와 같이 단순화할 수 있다.

$deltaDist_y = |\frac{|rayDir|}{rayDir_y}|$

$deltaDist_x$**도 마찬가지로 구할 수 있다.**

## sideDist 구하기
$(raxDir_x > 0) sideDist_x = (mapPos_x + 1 - playerPos_x)(deltaDist_x)$

$(raxDir_x < 0) sideDist_x = (playerPos_x - mapPos_x)(deltaDist_x)$

$(rayDir_y > 0) sideDist_y = (mapPos_y + 1 - playerPos_y)(deltaDist_y)$

$(rayDir_y < 0) sideDist_y = (playerPos_y - mapPos_y)(deltaDist_y)$

초기 $sideDist$의 길이는 $deltaDist$와 정확히 똑같지 않을 수 있다.

이 값을 따로 구해서 $deltaDist$와 더해야 한다.

---

$sideDist$ ***유도***

우리는 $sideDist$의 높이를 알 수 있다. 이 높이를 $b$라고 표기한다.

예: $sideDist_y$

처음으로 만나는 선에 따른 높이는 광선의 방향에 따라 두 가지로 나뉜다.

$(rayDir_y > 0) b = mapPos_y + 1 - playerPos_y$

$(rayDir_y < 0) b = playerPos_y - mapPos_y$

$deltaDist_y$와 각 축에 수직인 직선들로 만들어진 삼각형과 $sideDist_y$와 각 축에 수직인 직선들로 만들어진 삼각형은 서로 닮음이다.

앞서 $deltaDist_y$도 구했고, $deltaDist_y$와 $sideDist_y$의 높이를 모두 알고 있으므로 이를 가지고 비례식을 세울 수 있다.

$sideDist_y : b = deltaDist_y : 1$

$sideDist_y = b \times deltaDist_y$

최종적으로, $rayDir_y$의 방향에 따라 아래와 같이 구할 수 있다.

$(rayDir_y > 0) sideDist_y = (mapPos_y + 1 - playerPos_y)(deltaDist_y)$

$(rayDir_y < 0) sideDist_y = (playerPos_y - mapPos_y)(deltaDist_y)$

$sideDist_x$**도 마찬가지로 구할 수 있다.**
