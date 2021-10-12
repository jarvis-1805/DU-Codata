function returnMsg(element) {
  const message = document.getElementById("message");
  message.innerHTML = element.innerHTML;
}

function addItem(event) {
  event.preventDefault();
  const toAdd = document.getElementById("toAdd");
  if (toAdd.value !== "") {
    const li = document.createElement("li");
    li.innerHTML = toAdd.value;
    li.id = window.crypto.getRandomValues(new Uint32Array(1));
    li.addEventListener("click", () => {
      getNextSibling(li.id);
    });
    li.addEventListener("dblclick", () => {
      getPreviousSibling(li.id);
    });
    document.getElementById("list").appendChild(li);
    toAdd.value = "";
  }
}

function getFirstChild() {
  const first = document.getElementById("list").firstChild;
  if (first !== null) {
    document.getElementById("result").innerHTML = "FIRST ELEMENT: " + first.innerHTML;
  }
}

function getLastChild() {
  const last = document.getElementById("list").lastChild;
  if (last !== null) {
    document.getElementById("result").innerHTML = "LAST ELEMENT: " + last.innerHTML;
  }
}

function getParentNode() {
  const parent = document.getElementById("list").parentNode;
  document.getElementById("result").innerText = "\n" + "PARENT ID: " + parent.id + parent.innerHTML;
}

function getChildNode() {
  var childNodes = "";
  document.getElementById("list").childNodes.forEach((node) => {
    childNodes += node.innerHTML + "";
  });
  document.getElementById("result").innerHTML = childNodes;
}

function removeFirstChild() {
  var first = document.getElementById("list").firstChild;
  if (first !== null) {
    document.getElementById("list").firstChild.remove();
    document.getElementById("result").innerHTML = "REMOVED: " + first.innerHTML;
  }
}

function getNextSibling(id) {
  const nextSibling = document.getElementById(id).nextSibling;
  if (nextSibling !== null) {
    document.getElementById("result").innerHTML = "NEXT SIBLING: " + nextSibling.innerHTML;
  }
}

function getPreviousSibling(id) {
  const prevSibling = document.getElementById(id).previousSibling;
  if (prevSibling !== null) {
    document.getElementById("result").innerHTML = "PREVIOUS SIBLING: " + prevSibling.innerHTML;
  }
}

function displayAttr() {
  const element = document.getElementById("id-of-this-element");
  const className = element.getAttribute("class");
  const style = element.getAttribute("style");
  const id = element.getAttribute("id");
  document.getElementById("display-attributes").innerHTML =
    "Class - " + className + "<br>" +
    "Style - " + style + "<br>" +
    "ID - " + id + "<br>";
}

function changeColor(color) {
  const listItems = document.getElementsByTagName("li");
  for (var i = 0; i < listItems.length; i++) {
    listItems[i].setAttribute("style", `color:${color}`);
  }
}