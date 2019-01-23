class Catan:

    def __init__(self,grid):
        self.grid=grid
        self.invalid=set()
        self.n=len(grid)
        self.grid.append([None] * (self.n+2))

    def findPointLocs(self):
        #maps each index to its accessible hexagons
        point_dic={}
        #beginning row
        row=0
        for col in range(3):
            point_dic[(row,col)]=[self.grid[0][0]]
        #later rows
        for row in range(1,self.n+1):
            for col in range(row*2+3):
                point_dic[(row,col)]=[]

                if(col%2==0):
                    # top
                    if(col>0 and col<row*2+2):
                        point_dic[(row,col)].append(self.grid[row-1][(col-1)//2])
                    #bottom left
                    if(col>0):
                        point_dic[(row,col)].append(self.grid[row][(col-1)//2])
                    #bottom right
                    if(col<row*2+2):
                        point_dic[(row,col)].append(self.grid[row][(col-1)//2+1])
                else:
                    # top left
                    if(col>1):
                        point_dic[(row,col)].append(self.grid[row-1][col//2-1])
                    # top right
                    if(col<row*2+1):
                        point_dic[(row,col)].append(self.grid[row-1][col//2])
                    # bottom
                    point_dic[(row,col)].append(self.grid[row][col//2])

        self.point_dic=point_dic
        return point_dic

    def getProbabilityValues(self):
        #converts each group of accessible hexagons to total value
        value_dict={}
        for key,val in self.point_dic.items():
            p = 0
            for v in val:
                if (v != None and v < 7):
                    p += v-1
                elif (v != None and v > 7):
                    p += 13 - v
            value_dict[key]=p
        self.value_dict = value_dict

        return value_dict

    def sortValues(self):
        arr=[]
        for x in range(20):
            arr.append([])
        for key,val in self.value_dict.items():
            arr[val].append(key)
        flat_arr = [item for subarr in arr for item in subarr]
        self.most_val=flat_arr[::-1]

    def inbounds(self,pos):
        row,col=pos
        return (col>=0 and row>=0 and row<=self.n and col<=row*2+2)

    def get_neighbors(self,pos):
        row,col=pos
        positions=[(row,col+1),(row,col-1)]
        if(col%2==0):
            positions.append((row+1,col+1))
        elif(col%2==1):
            positions.append((row-1,col-1))
        valid_positions=[]
        for p in positions:
            if(self.inbounds(p)):
                valid_positions.append(p)
        return valid_positions

    def most_valuable_pos(self):
        #used by 2nd to 4th turn
        for pos in self.most_val:
            if(pos not in self.invalid):
                return pos

    def most_valuable_eight_pos(self):
        #used by first turn
        arr=[]
        for pos in self.most_val:
            if(pos not in self.invalid):
                arr.append(pos)
                if(len(arr)>=8):
                    return arr

    def optimized_dfs(self,turns_left):
        self.invalid=set()
        res,path=self.optimized_dfs_helper(4)
        #to get path
        # print(res)
        # for p in path:
        #     print(p,self.value_dict[p])
        return res

    def optimized_dfs_helper(self,turns_left):
        if(turns_left==1):
            ind=self.most_valuable_pos()
            return self.value_dict[ind],[ind]

        else:
            best_diff=None
            best_path=[]
            positions=[]
            if(turns_left==4):
                #more flexible, must cover eight possible positions
                pos=self.most_valuable_eight_pos()
                for p in pos:
                    positions=positions+self.get_neighbors(p)
                positions+=pos
                positions=set(positions)

            else:
                #must cover most valuable position
                best_pos=self.most_valuable_pos()
                positions=[best_pos]+self.get_neighbors(best_pos)

            for p in positions:
                #taken
                if(p in self.invalid):
                    continue
                overridden=set({p})
                self.invalid.add(p)
                for p2 in self.get_neighbors(p):
                    if( p2 not in self.invalid ):
                        overridden.add(p2)
                        self.invalid.add(p2)

                res,path=self.optimized_dfs_helper(turns_left-1)

                if(res==None):
                    #no sol
                    continue
                #restore
                for o in overridden:
                    self.invalid.remove(o)

                if(turns_left==3 or turns_left==2):
                    #want min
                    if(best_diff == None or -self.value_dict[p] + res < best_diff):
                        best_diff = -self.value_dict[p] + res
                        best_path = [p] + path
                else:
                    #want max
                    if(best_diff == None or self.value_dict[p] + res > best_diff):
                        best_diff = self.value_dict[p] + res
                        best_path = [p] + path
        return best_diff,best_path

if __name__ == "__main__":
    tests=int(input())
    for t in range(tests):
        n = int(input())
        nums=[]
        for x in range(n):
            l=list(map(int,input().split()))
            nums.append(l)

        C = Catan(nums)
        C.findPointLocs()
        C.getProbabilityValues()
        C.sortValues()
        res=C.optimized_dfs(4)
        print(res)