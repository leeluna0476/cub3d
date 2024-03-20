# 벽의 높이 구하기
$h = mapHeight$

$lineHeight = \frac{h}{perpWallDist}$

벽을 더 높거나 낮게 그리고 싶다면 $h$에 변화를 주면 된다.

높이를 구했다면 화면 중앙을 기준으로 수직선을 그리면 된다.

$drawStart = \frac{\frac{-lineHeight}{2 + h}}{2}$

$drawEnd = \frac{\frac{lineHeight}{2 + h}}{2}$

만약 $drawStart$가 $0$ 미만이 되거나 $drawEnd$가 $h$ 이상이 된다면 화면 밖으로 이탈한 것이기 때문에 각각 $0$ 또는 $h - 1$로 보정한다.

# 벽에 텍스쳐 입히기
