function doGet(e) {
  var sheet = SpreadsheetApp.getActiveSpreadsheet().getActiveSheet();
  
  if (e.parameter.data) {
    var values = e.parameter.data.split(",");
    if (values.length === 3) {
      sheet.appendRow([new Date(), values[0], values[1], values[2]]);
      return ContentService.createTextOutput("Success: Data saved");
    } else {
      return ContentService.createTextOutput("Error: Invalid QR Format");
    }
  }
  return ContentService.createTextOutput("Error: No data received");
}
