// question now

class Node {
  constructor(val) {
    this.value = val;
    this.next = null;
  }
}

class LinkedList {
  constructor(val) {
    this.head = new Node(val);
    this.length = 0;
  }

  add(val) {
    let trav = this.head;

    console.log(trav.value);

    while (trav !== null) {
      trav = trav.next;
    }

    trav = new Node(val);
  }

  display() {
    let display = "";
    let trav = this.head;

    while (trav.next !== null) {
      display += String(trav.value) + " -> ";
      trav = trav.next;
      console.log(display, trav.next.value);
    }

    console.log(display + "null");
  }
}

// -----------------------------------------------------------------------------

let ll = new LinkedList(3);
ll.display();
ll.add(5);
ll.display();
