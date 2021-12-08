function logData() {
    // get data from the form
    const manuf = $("#manufacturer").val();
    const model = $("#model").val();
    const year = $("#manuf_year").val();
    const fuel = $("#fuel_type :selected").text();
    const color = $("#color").val();
    const seat_cap = $("#seating_cap").val();
    const cubic_cap = $("#cubic_cap").val();

    // creating book object
    const car = {
        "Manufacturer Name": manuf,
        "Model": model,
        "Manufactured Year": year,
        "Fuel Type": fuel,
        "Color": color,
        "Seating Capacity": seat_cap,
        "Cubic Capacity": cubic_cap
    };

    // log data
    console.log("Car Object: ", car);
    console.log("JSON Object: ", JSON.stringify(car));
}