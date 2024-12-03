import csv
import sys

def read_file(file_name: str):
    with open(file_name) as file:
        return [row for row in csv.reader(file, delimiter=" ")]


def safe_reports(reports: list):
    return [report for report in reports if is_safe(report)]


def unsafe_reports(reports: list):
    return [report for report in reports if not is_safe(report)]


def problem_dampener(unsafe_report: list):
    for level in unsafe_report:
        new_report = unsafe_report.copy()
        new_report.remove(level)
        if is_safe(new_report):
            print(new_report)
            return new_report


def is_safe(report):
    for prev, current, next in zip(list([None]) + report[:-1], report, report[1:] + list([None])):
        current_level = int(current)
        prev_level = int(prev) if prev is not None else None
        next_level = int(next) if next is not None else None

        if next_level is not None and abs(current_level - next_level) >= 4:
            return False

        if next_level is not None and abs(current_level - next_level) == 0:
            return False

        if prev_level is not None and next_level is not None:
            if prev_level >= current_level <= next_level or prev_level <= current_level >= next_level:
                return False
    return True


if __name__ == '__main__':
    file_name = sys.argv[1]
    # Get list of reports
    reports = read_file(file_name)
    safe_reports = safe_reports(reports)
    dampened_reports = [problem_dampener(report) for report in unsafe_reports(reports) if problem_dampener(report) is not None]
    print(f'Number of safe reports: {len(safe_reports)}')

    print(f'Number of dampened reports: {len(dampened_reports)}')
    print(f'Total number of safe reports: {len(safe_reports) + len(dampened_reports)}')
