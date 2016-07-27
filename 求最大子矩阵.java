import java.util.*;

class Untitled {
	public  int maxRecSize (int[][] map) {
		if (map == null || map.length == 0 || map[0].length == 0) {
			return 0;
		}
		int maxArea = 0;
		int [] height = new  int [map[0].length];
		for (int i = 0 ; i < map.length; i ++) {
			for (j = 0; j < map[0].length; j++) {
				height[j] = map[i][j] == 0 ? 0 : height[j] + 1;
			}
			maxArea = Math.max(maxArea, maxRecFromottom(height));
		}
		return maxArea;
	}
	
	public  int maxRecFromottom(int[] height) {
		if (height == null || height.length == 0) {
			return 0;
		}
		int maxArea = 0;
		Stack<Integer> stack = new  Stack<Integer>();
		for (int i = 0; i < height.length;i++) {
			while (!stack.isEmpty() && height[i] <= height[stack.peek()]) {
				int j = stack.pop();
				int k = stack.isEmpty() ? -1 : stack.peek();
				int currentArea = (i - k - 1) * height[j];
				maxArea = Math.max(maxArea, currentArea);
			}
			stack.push(i);
		}
		while (!stack.isEmpty()) {
			int j = stack.pop();
			int k = stack.isEmpty() ? -1 : stack.peek();
			int curArea = (height.length - k - 1) * height[j];
			maxArea = Math.max(maxArea, curArea);
		}
		return maxArea;
	}
	public static void main(String[] args) {
		
	}
}