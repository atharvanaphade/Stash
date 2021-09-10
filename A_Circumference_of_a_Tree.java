import java.io.*;
import java.util.*;

public class A_Circumference_of_a_Tree {

    static class Node {
        ArrayList<Node> adj = new ArrayList<Node>();
        int dist;
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        if (n == 1) {
            System.out.println(0);
            return;
        }
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; i++) nodes[i] = new Node();
        for (int i = 1; i < n; i++) {
           int a = sc.nextInt() - 1, b = sc.nextInt() - 1;
           nodes[a].adj.add(nodes[b]);
           nodes[b].adj.add(nodes[a]);
        }
        bfs(nodes[0], nodes);
        Node farthest = farthest(nodes);
        bfs(farthest, nodes);
        System.out.println(3 * farthest(nodes).dist);
        sc.close();
    }

    static Node farthest (Node[] nodes) {
        Node max = nodes[0];
        for (Node nn : nodes) {
            if (nn.dist > max.dist) {
                max = nn;
            }
        }
        return max;
    }

    static void bfs (Node from, Node[] nodes) {
        for (Node nn : nodes) nn.dist = -1;
        from.dist = 0;
        ArrayDeque<Node> q = new ArrayDeque<Node>();
        q.add(from);
        while (!q.isEmpty()) {
            Node next = q.remove();
            for (Node nn : next.adj) {
                if (nn.dist == -1) {
                    nn.dist = next.dist + 1;
                    q.add(nn);
                }
            }
        }
    }
}