from tkinter import*
from tkinter import PhotoImage
















fen=Tk()
fen.title('Zlvl maker')
canvas=Canvas(fen,width=384*4,height=216*4,bg="white")
canvas.pack()



gridtiles=[]
for i in range(9):
    gridtiles.append([])
    for j in range(16):
        gridtiles[i].append(0)



gridground=[]
for i in range(9):
    gridground.append([])
    for j in range(16):
        gridground[i].append(0)



gridcollisions=[]
for i in range(9):
    gridcollisions.append([])
    for j in range(16):
        gridcollisions[i].append(0)


griddoor=[]
for i in range(9):
    griddoor.append([])
    for j in range(16):
        griddoor[i].append(0)

ground=[['Nothing on the floor',0],["pot",1]]

tiles=[["cave",0],["cave_wall_btm",1],
       ["cave_wall_left",2],["cave_wall_top",3],
       ["cave_wall_right",4],["cave_btm_left",5],
       ["cave_top_left",6],["cave_top_right",7],
       ["cave_btm_right",8],["door_top_left",9]
       ,["door_top_right",10],["door_right_top",11]
       ,["door_right_btm",12],["door_btm_left",13],["door_btm_right",14]
       ,["door_left_top",15],["door_left_btm",16]]

collisions=[["No collision",0],["collision",1]]
door=[["No door collision",0],["collision",1],["condition",2]]


cave = PhotoImage(file="projects/Zelda/sprites_zelda/tiles/cave.png").zoom(4,4)
cave_btm_left = PhotoImage(file="projects/Zelda/sprites_zelda/tiles/cave_bottom_left.png").zoom(4,4)
cave_top_left = PhotoImage(file="projects/Zelda/sprites_zelda/tiles/cave_high_left.png").zoom(4,4)
cave_top_right = PhotoImage(file="projects/Zelda/sprites_zelda/tiles/cave_high_right.png").zoom(4,4)
cave_btm_right = PhotoImage(file="projects/Zelda/sprites_zelda/tiles/cave_bottom_right.png").zoom(4,4)
cave_wall_btm = PhotoImage(file="projects/Zelda/sprites_zelda/tiles/cave_wall_1.png").zoom(4,4)
cave_wall_left = PhotoImage(file="projects/Zelda/sprites_zelda/tiles/cave_wall_2.png").zoom(4,4)
cave_wall_top = PhotoImage(file="projects/Zelda/sprites_zelda/tiles/cave_wall_3.png").zoom(4,4)
cave_wall_right = PhotoImage(file="projects/Zelda/sprites_zelda/tiles/cave_wall_4.png").zoom(4,4)




selected=tiles
selected_item=0

def change(event):
    global selected,selected_item,tiles,ground,collisions,door
    selected_item=0
    if selected==tiles:
        selected=collisions
    elif selected==collisions:
        selected=door
    elif selected==door:
        selected=ground
    else:
        selected=tiles
    print(selected[selected_item])

def changem(event):
    global selected,selected_item,tiles,ground,collisions
    selected_item=0
    if selected==tiles:
        selected=ground
    elif selected==ground:
        selected=door
    elif selected==door:
        selected=collisions
    else:
        selected=tiles
    print(selected[selected_item])

def changeitem(event):
    global selected,selected_item,ground,tiles,collisions
    if selected_item<len(selected)-1:
        selected_item+=1
    else:
        selected_item=0
    print(selected[selected_item])

def changemitem(event):
    global selected,selected_item,ground,tiles,collisions
    if selected_item>0:
        selected_item-=1
    else:
        selected_item=len(selected)-1
    print(selected[selected_item])


def draw_cells():
    canvas.delete('all')
    print(gridground)
    for x in range(17):
        canvas.create_line(x*96,0,x*96,216*4)
    for y in range(9):
        canvas.create_line(0,y*96,384*4,y*96)
    for x in range(16):
        for y in range(9):
            if gridtiles[y][x]==0:
                image=cave 
                image_item = canvas.create_image(x*96, y*96, image=image, anchor=NW)

            elif gridtiles[y][x]==1:
                image=cave_wall_btm
                image_item = canvas.create_image(x*96, y*96, image=image, anchor=NW)

            elif gridtiles[y][x]==2:
                image=cave_wall_left
                image_item = canvas.create_image(x*96, y*96, image=image, anchor=NW)

            elif gridtiles[y][x]==3:
                image=cave_wall_top
                image_item = canvas.create_image(x*96, y*96, image=image, anchor=NW)

            elif gridtiles[y][x]==4:
                image=cave_wall_right
                image_item = canvas.create_image(x*96, y*96, image=image, anchor=NW)

            elif gridtiles[y][x]==5:
                image=cave_btm_left
                image_item = canvas.create_image(x*96, y*96, image=image, anchor=NW)
            
            elif gridtiles[y][x]==6:
                image=cave_top_left
                image_item = canvas.create_image(x*96, y*96, image=image, anchor=NW)
            
            elif gridtiles[y][x]==7:
                image=cave_top_right
                image_item = canvas.create_image(x*96, y*96, image=image, anchor=NW)
            
            elif gridtiles[y][x]==8:
                image=cave_btm_right
                image_item = canvas.create_image(x*96, y*96, image=image, anchor=NW)
            
            else:
                canvas.create_text(x*96+48,y*96+48,text=tiles[gridtiles[y][x]],fill='red',font=('Arial', 15))
            if gridground[y][x]==1:
                canvas.create_text(x*96+48,y*96+48,text="pot",fill='red',font=('Arial', 40))

            if gridcollisions[y][x]==1:
                canvas.create_rectangle( x*96,y*96,(x+1)*96,(y+1)*96 , outline='red',width=5)
            if griddoor[y][x]==1:
                canvas.create_line(x*96,y*96,(x+1)*96,(y+1)*96,fill='green',width=5)
                canvas.create_line(x*96,y*96+96,(x+1)*96,y*96,fill='green',width=5)
            if griddoor[y][x]==2:
                canvas.create_line(x*96,y*96+96,(x+1)*96,y*96,fill='green',width=5)


def export(event):
    for x in range(16):
        for y in range(9):
            if gridcollisions[y][x]!=0:
                print('    grid['+str(x)+']['+str(y)+'][0]='+str(gridcollisions[y][x])+';')
            if gridground[y][x]!=0:
                print('    grid['+str(x)+']['+str(y)+'][1]='+str(gridground[y][x])+';')
            if gridtiles[y][x]!=0:
                print('    grid['+str(x)+']['+str(y)+'][2]='+str(gridtiles[y][x])+';')
            if griddoor[y][x]!=0:
                print('    grid['+str(x)+']['+str(y)+'][3]='+str(griddoor[y][x])+';')


def fill(event):
    global gridcollisions
    gridcollisions=[]
    for i in range(9):
        gridcollisions.append([])
        for j in range(16):
            gridcollisions[i].append(0)
    for x in range(16):
        for y in range(9):
            if gridground[y][x]!=0 or gridtiles[y][x]!=0:
                gridcollisions[y][x]=1
    draw_cells()

def put(event):
    global selected,selected_item,gridcollisions,gridground,gridtiles
    x=event.x
    y=event.y
    x2=int(x/96)
    y2=int(y/96)
    if selected==collisions:
        gridcollisions[y2][x2]=selected[selected_item][1]
    elif selected==tiles:
        gridtiles[y2][x2]=selected[selected_item][1]
    elif selected==door:
        griddoor[y2][x2]=selected[selected_item][1]
    else:
        gridground[y2][x2]=selected[selected_item][1]
    draw_cells()

fen.bind('<Left>',change)
fen.bind('<Right>',changem)
fen.bind('<Up>',changeitem)
fen.bind('<Down>',changemitem)
fen.bind('<Button-1>',put)
fen.bind('<Return>',export)
fen.bind('<space>',fill)

draw_cells()
fen.mainloop()