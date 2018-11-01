class Solution {
	public int catMouseGame(int[][] graph) {
		int N = graph.length;
		final int DRAW = 0, MOUSE = 1, CAT = 2;
		int[][][] color = new int[50][50][3];
		int[][][] degree = new int[50][50][3];

		for (int m = 0; m < N; ++m) {
			for (int c = 0; c < N; ++c) {
				degree[m][c][1] = graph[m].length;
				degree[m][c][2] = graph[c].length;
				for (int x: graph[c]) {
					if (x == 0)	degree[m][c][2]--;
					break;
				}
			}
		}
		Queue<int[]> queue = new LinkedList();
		for (int i = 0; i < N; ++i) {
			for (int t = 1; t <= 2; ++t) {
				color[0][i][t] = MOUSE;
				queue.add(new int[]{0, i, t, MOUSE});
				if (i > 0) {
					color[i][i][t] = CAT;
					queue.add(new int[]{i, i, t, CAT});
				}
			}
		}
		while (!queue.isEmpty()) {
			int[] node = queue.remove();
			int i = node[0], j = node[1], t = node[2], c = node[3];
			for (int[] parent: parents(graph, i, j, t)) {
				int i2 = parent[0], j2 = parent[1], t2 = parent[2];
				if (color[i2][j2][t2] == DRAW) {
					if (t2 == c) {
						color[i2][j2][t2] = c;
						queue.add(new int[]{i2, j2, t2, c});
					} else {
						degree[i2][j2][t2]--;
						if (degree[i2][j2][t2] == 0) {
							color[i2][j2][t2] = 3 - t2;
							queue.add(new int[]{i2, j2, t2, 3 - t2});
						}
					}
				}
			}
		}
		return color[1][2][1];
	}
	public List<int[]> parents(int[][] graph, int m, int c, int t) {
		List<int[]> ans = new ArrayList();
		if (t == 2) {
			for (int m2: graph[m]) {
				ans.add(new int[]{m2, c, 3 - t});
			}
		} else {
			for (int c2: graph[c]) {
				if (c2 > 0) {
					ans.add(new int[]{m, c2, 3 - t});
				}
			}
		}
        return ans;
	}
}