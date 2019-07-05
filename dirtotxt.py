import os
import os.path as osp
img_root = '/data/images'
json_root = '/data/jsons'
all_f = open('all.txt','w')
train_f = open('train.txt','w')
test_f = open('test.txt','w')
for idx,img_name in enumerate(os.listdir(img_root)):#img_name == bmp
    write_Str = osp.join(img_root,img_name)+' '+osp.join(json_root,osp.splitext(img_name)[0]+'.json')+'\n'
    all_f.write(write_Str)
    if idx%10<8:#%
        train_f.write(write_Str)
    else:
        test_f.write(write_Str)
all_f.close()
train_f.close()
test_f.close()

def get_binary_list(num, p, pos_id = 0):
    neg_id = (pos_id + 1) % 2
    random.seed(num)
    train_len = int(num * p)
    test_len = num - train_len
    bins = [pos_id] * train_len + [neg_id] * test_len
    random.shuffle(bins)
    return bins
