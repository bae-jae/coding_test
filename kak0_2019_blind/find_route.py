pre_order = []
last_order = []

def make_tree(nodeinfo):
    """현재 노드를 기준으로 하여 이진 트리를 구성한다.

    현재 레밸보다 아래에 있는 노드 중에 x값이 root의 x 값보다 작은 것을 왼쪽으로 큰 부분을 오른쪽으로 보낸다.

    Args:
        nodeinfo (_type_): y 축을 기준으로 정렬된 node
    """
    global pre_order, last_order

    if not nodeinfo:
        return

    root_node = nodeinfo.pop(0)
    node_list = nodeinfo[:]

    pre_order.append(root_node[2])
    
    make_tree([node for node in node_list if node[0] < root_node[0]])
    make_tree([node for node in node_list if node[0] > root_node[0]])

    last_order.append(root_node[2])
    
    return

def solution(nodeinfo):
    """전위 순회와 후위 순회의 결과를 반환한다.

    Args:
        nodeinfo (_type_): 입력으로 주어진 노드

    Returns:
        _list_: 전위 순회와 후위 순회의 결과를 반환한다.
    """
    for idx, node in enumerate(nodeinfo):
        node.append(idx + 1)
    nodeinfo.sort(key=lambda nodeinfo:(-nodeinfo[1], nodeinfo[0]))

    make_tree(nodeinfo)

    return [pre_order, last_order]




if __name__ == "__main__":
    nodeinfo = [[5,3],[11,5],[13,3],[3,5],[6,1],[1,3],[8,6],[7,2],[2,2]]
    result = [[7,4,6,9,1,8,5,2,3],[9,6,5,8,1,4,3,2,7]]

    print(solution(nodeinfo))
