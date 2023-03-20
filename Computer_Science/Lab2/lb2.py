L, R, N = -1, 1, 0
states = {
    'q_start': {'0': ['0', R, 'q_start'], '1': ['1', R, 'q_start'], '2': ['2', R, 'q_start'],
                 '+': ['+', R, 'q_num'], '-': ['-', R, 'q_num'], ' ': [' ', R, 'q_start']},
    'q_num': {'0': ['0', N, 'q_end'], '1': ['1', L, 'q_action_1'], '2': ['2', L, 'q_action_2']},
    'q_action_1': {'0': ['1', N, 'q_end'], '1': ['2', N, 'q_end'], '2': ['0', L, 'q_action_1'],
                    '+': ['+', L, 'q_action_1'], '-': ['-', L, 'q_action_-1'], ' ': ['1', N, 'q_end']},
    'q_action_2': {'0': ['2', N, 'q_end'], '1': ['0', L, 'q_action_1'], '2': ['1', L, 'q_action_1'],
                    '+': ['+', L, 'q_action_2'], '-': ['-', L, 'q_action_-2'], ' ': ['2', N, 'q_end']},
    'q_action_-1': {'0': ['2', L, 'q_action_-1'], '1': ['0', L, 'q_test_0'], '2': ['1', N, 'q_end']},
    'q_action_-2': {'0': ['1', L, 'q_action_-1'], '1': ['2', L, 'q_action_-1'], '2': ['0', L, 'q_test_0']},
    'q_test_0': {'0': ['0', N, 'q_end'], '1': ['1', N, 'q_end'], '2': ['2', N, 'q_end'],
                  ' ': [' ', R, 'q_del_0']},
    'q_del_0': {'0': [' ', R, 'q_del_0'], '1': ['1', N, 'q_end'], '2': ['2', N, 'q_end'],
                 '+': ['+', L, 'q_del_0'], '-': ['-', L, 'q_del_0'], ' ': ['0', N, 'q_end']}
}

current_state = 'q_start'
index = 0
line = list(input())
while current_state != 'q_end':
    new_sign, step, new_state = states[current_state][line[index]]
    line[index] = new_sign
    current_state = new_state
    index += step

line = ''.join(line)
print(line)