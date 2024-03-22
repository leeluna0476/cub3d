# 벽의 높이 구하기
$h = mapHeight$

$lineHeight = \frac{h}{perpWallDist}$

벽을 더 높거나 낮게 그리고 싶다면 $h$에 변화를 주면 된다.

높이를 구했다면 화면 중앙을 기준으로 수직선을 그리면 된다.

$drawStart = \frac{-lineHeight + h}{2}$

$drawEnd = \frac{lineHeight + h}{2}$

만약 $drawStart$가 $0$ 미만이 되거나 $drawEnd$가 $h$ 이상이 된다면 화면 밖으로 이탈한 것이기 때문에 각각 $0$ 또는 $h - 1$로 보정한다.

# 벽에 텍스쳐 입히기
벽의 어느 부분에 광선이 충돌했는지 알 수 있기 때문에 벽에 텍스쳐를 입힐 수 있다.

$x$축으로만 광선을 쏘기 때문에 충돌 지점의 $x$ 좌표만 안다면 $y$축은 벽의 높이에 따라서 잘 그리면 된다.

$playerPos$로부터 광선의 방향으로 ($x = 0$ or $y = 0$)수평선을 그리고 광선의 충돌 지점으로부터 이에 대한 수직선을 그렸을 때, $playerPos$로부터 이 교점까지의 거리를 $t$라고 표기한다.

$rayDir : sideDist = playerDir : perpWallDist$

$rayDir : sideDist = rayDir_x : t$

위 두 비례식은 좌변이 같기에 아래와 같은 비례식이 성사된다.

$playerDir : perpWallDist = rayDir_x : t$

최종적으로 아래와 같이 구할 수 있다.

$t \times playerDir = perpWallDist \times rayDir_x$

$t$와 $playerPosX$를 더하면 맵의 첫 부분부터의 거리가 나오고, 정수 부분을 빼면 텍스쳐의 $x$ 좌표를 구할 수 있다.

광선이 벽의 어느 방면에 충돌했는지에 따라 텍스쳐의 $x$ 좌표가 왼쪽부터 시작인지, 오른쪽부터 시작인지 구별해야 한다. 유저의 시야에서 보이는 방향과 실제 방향이 다르기 때문에 서쪽과 남쪽은 뒤집혀서 보일 수 있다.

반대 방향일 경우 $1$에서 텍스쳐의 $x$ 좌표를 빼야 한다.
