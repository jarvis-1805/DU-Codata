function logData() {
    // get data from the form
    const name = document.getElementById("book_name").value;
    const author = document.getElementById("book_author").value;
    const price = document.getElementById("book_price").value;
    const publisher = document.getElementById("book_publisher").value;
    const category = document.getElementById("book_category").value;

    // creating book object
    const book = {
        name: name,
        author: author,
        price: price,
        publisher: publisher,
        category: category
    };

    // log data
    console.log("Book Object: ", book);
    console.log("JSON Object: ", JSON.stringify(book));
}