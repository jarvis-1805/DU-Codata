function logData() {
    // get data from the form
    const name = document.getElementById("pet_name").value;
    const age = document.getElementById("pet_age").value;
    const weight = document.getElementById("pet_weight").value;
    const type = document.getElementById("pet_type").value;
    const likes = document.getElementById("pet_likes").value;

    // creating pet object
    const pet = {
        name: name,
        age: age,
        weight, weight,
        type: type,
        likes: likes
    };

    // log data
    console.log("Pet Object: ", pet);
    console.log("JSON Object: ", JSON.stringify(pet));
}