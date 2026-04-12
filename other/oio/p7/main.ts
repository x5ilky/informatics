const f = Deno.readTextFileSync("./P7_input.txt")
const lns = f.replace(/\r/g,"").split("\n").slice(1,-1)
let s=""
const options=[
"ALEXA",
"ALEX",
"AWU",
"JUSTIN",
"NATHAN",
"PHILIP",
"YMQ",
]


for (const ln of lns){
    if(ln.endsWith(".")||ln[0].toUpperCase()==ln[0])
        s+="NATHAN\n";
    else
        s+=options[Math.floor(Math.random()*options.length)]+"\n";
}
Deno.writeTextFileSync("output.txt", s)
